# $NetBSD: Makefile,v 1.1.1.1 2002/07/14 09:27:17 rh Exp $
#

DISTNAME=       iroffer1.2b13
PKGNAME=	${DISTNAME:S/iroffer/iroffer-/}
CATEGORIES=	chat net
MASTER_SITES=	http://iroffer.org/archive/v1.2/beta/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lebsack@mac.com
HOMEPAGE=	http://iroffer.org/
COMMENT=	IRC (Internet Relay Chat) DCC OfferBot

do-configure:
	cd ${WRKSRC}; ./Configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/iroffer
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${PREFIX}/share/doc/iroffer/COPYING
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/iroffer/README
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW \
		${PREFIX}/share/doc/iroffer/WHATSNEW
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/iroffer
	${INSTALL_DATA} ${WRKSRC}/sample.config \
		${PREFIX}/share/examples/iroffer/sample.config
	${INSTALL_DATA} ${WRKSRC}/iroffer.cron \
		${PREFIX}/share/examples/iroffer/iroffer.cron

.include "../../mk/bsd.pkg.mk"
