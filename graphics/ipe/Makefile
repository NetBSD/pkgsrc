# $NetBSD: Makefile,v 1.22 2022/07/02 16:53:23 ryoon Exp $

DISTNAME=	ipe-7.2.7-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	https://dl.bintray.com/otfried/generic/ipe/7.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipe.otfried.org/
COMMENT=	Drawing editor for creating figures in PDF or (e)PS
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config
MAKE_ENV+=	QT_SELECT=5
MAKE_ENV+=	IPEPREFIX=${DESTDIR}${PREFIX}
MAKE_ENV+=	LUA_PACKAGE=lua-5.3
MAKE_ENV+=	DL_LIBS=${DL_LIBS}
MAKE_ENV+=	IPEMANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

CHECK_INTERPRETER_SKIP=	share/ipe/${PKGVERSION_NOREV}/scripts/*.lua

LUA_VERSIONS_ACCEPTED=	53

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
