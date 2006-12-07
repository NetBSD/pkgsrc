# $NetBSD: Makefile,v 1.1.1.1 2006/12/07 20:32:15 plunky Exp $

DISTNAME=		btpin-qt-1.0
CATEGORIES=		sysutils
MASTER_SITES=		http://homepages.rya-online.net/plunky/

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth PIN Client

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

BUILD_DEFS+=		PKGMANDIR
USE_LANGUAGES=		c++

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -after	\
		target.path=${PREFIX}/bin		\
		man.path=${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
