# $NetBSD: Makefile,v 1.57 2020/04/12 08:28:52 adam Exp $

DISTNAME=	ibus-qt-1.3.3-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	18
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/ibus/ibus-qt/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus-qt
COMMENT=	Qt IBus library and Qt input method plugin
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

# optionally, but required by configure.
#BUILD_DEPENDS+=	doxygen>=1.6:../../devel/doxygen
TOOLS_NOOP=		doxygen

# avoid lib64
CMAKE_ARGS+=		-DLIBDIR=lib

BUILDLINK_API_DEPENDS.ibus+=	ibus>=1.3.7
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
