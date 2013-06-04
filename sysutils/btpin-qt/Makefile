# $NetBSD: Makefile,v 1.26 2013/06/04 22:17:03 tron Exp $

DISTNAME=		btpin-qt-1.5
PKGREVISION=		10
CATEGORIES=		sysutils
MASTER_SITES=		http://www.galant.ukfsn.org/

MAINTAINER=		plunky@rya-online.net
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
