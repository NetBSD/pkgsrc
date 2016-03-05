# $NetBSD: Makefile,v 1.31 2016/03/05 11:29:28 jperkin Exp $

DISTNAME=		btpin-qt-1.5
PKGREVISION=		14
CATEGORIES=		sysutils
MASTER_SITES=		http://www.NetBSD.org/~plunky/

MAINTAINER=		plunky@NetBSD.org
COMMENT=		Bluetooth PIN Client
LICENSE=		2-clause-bsd

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

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
