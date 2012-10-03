# $NetBSD: Makefile,v 1.8 2012/10/03 00:02:38 asau Exp $
#

DISTNAME=	iroffer1.3.b11
PKGNAME=	iroffer-1.3.11
CATEGORIES=	chat net
MASTER_SITES=	http://iroffer.org/archive/v1.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iroffer.org/
COMMENT=	IRC (Internet Relay Chat) DCC OfferBot

INSTALLATION_DIRS=	bin

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/iroffer
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/iroffer/COPYING
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/iroffer/README
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW \
		${DESTDIR}${PREFIX}/share/doc/iroffer/WHATSNEW
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/iroffer
	${INSTALL_DATA} ${WRKSRC}/sample.config \
		${DESTDIR}${PREFIX}/share/examples/iroffer/sample.config
	${INSTALL_DATA} ${WRKSRC}/iroffer.cron \
		${DESTDIR}${PREFIX}/share/examples/iroffer/iroffer.cron

.include "../../mk/bsd.pkg.mk"
