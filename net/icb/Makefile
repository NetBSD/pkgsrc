# $NetBSD: Makefile,v 1.10 1999/11/26 22:16:21 hubertf Exp $
#

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
