# $NetBSD: Makefile,v 1.11 1999/11/26 22:43:46 hubertf Exp $
#

# Note: The file ftp://ftp.icb.net/pub/icb/icb-0.9grok2.tar.gz is way
#	older than this here. It's got no readline support, tcl, ... - HF
DISTNAME=		icb-5.0.9
PKGNAME=		icb-5.0.9pl1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		cjs@netbsd.org
HOMEPAGE=		http://www.icb.net/

MIRROR_DISTFILE=	no

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
