# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:36 wiz Exp $
#

# Note: The file ftp://ftp.icb.net/pub/icb/icb-0.9grok2.tar.gz is way
#	older than this here. It's got no readline support, tcl, ... - HF
DISTNAME=		icb-5.0.9
PKGNAME=		icb-5.0.9pl1
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		cjs@netbsd.org
HOMEPAGE=		http://www.icb.net/

NO_SRC_ON_FTP=		"already in MASTER_SITE_LOCAL"

do-configure:
	@cd ${WRKSRC}; \
	${SED} -e s,@PREFIX@,${PREFIX},g ${FILESDIR}/config >${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/icbserverdb ${PREFIX}/libdata
	${INSTALL} -d ${PREFIX}/libdata/icb
	${INSTALL_SCRIPT} ${WRKSRC}/sample.icbrc \
		${WRKSRC}/contrib/bartender \
		${WRKSRC}/contrib/confuse \
		${WRKSRC}/contrib/echofile \
		${PREFIX}/libdata/icb

.include "../../mk/bsd.pkg.mk"
