# $NetBSD: Makefile,v 1.13 2012/01/23 20:53:27 joerg Exp $

DISTNAME=		btpin-qt-1.4
PKGREVISION=		10
CATEGORIES=		sysutils
MASTER_SITES=		http://homepages.rya-online.net/plunky/

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth PIN Client

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -after	\
		target.path=${PREFIX}/bin		\
		man.path=${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
