# $NetBSD: Makefile,v 1.4.2.1 2002/06/23 18:40:43 jlam Exp $
#

# Note: The file ftp://ftp.icb.net/pub/icb/icb-0.9grok2.tar.gz is way
#	older than this here. It's got no readline support, tcl, ... - HF
DISTNAME=		icb-5.0.9
PKGNAME=		icb-5.0.9pl1
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		cjs@netbsd.org
HOMEPAGE=		http://www.icb.net/
COMMENT=		Internet CB - a mostly-defunct chat client

NO_SRC_ON_FTP=		"already in MASTER_SITE_LOCAL"
USE_BUILDLINK_ONLY=	# defined

.include "../../mk/bsd.prefs.mk"

do-configure:
	@cd ${WRKSRC}; \
	${SED} -e s,@PREFIX@,${PREFIX},g ${FILESDIR}/config >${WRKSRC}/config
.	if (${OPSYS} == "Darwin")
	@${SED} -e s,-ltermcap,,g ${WRKSRC}/config >${WRKSRC}/config.new; \
	${MV} -f ${WRKSRC}/config.new ${WRKSRC}/config
.	endif


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/icbserverdb ${PREFIX}/libdata
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/icb
	${INSTALL_SCRIPT} ${WRKSRC}/sample.icbrc \
		${WRKSRC}/contrib/bartender \
		${WRKSRC}/contrib/confuse \
		${WRKSRC}/contrib/echofile \
		${PREFIX}/libdata/icb

.include "../../mk/bsd.pkg.mk"
