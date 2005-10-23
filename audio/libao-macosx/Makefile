# $NetBSD: Makefile,v 1.3 2005/10/23 19:05:34 rillig Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-macosx/}

COMMENT+=	(MacOS X plugin)

ONLY_FOR_PLATFORM+=	Darwin-*-*

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/ENABLE_MACOSX=no/ENABLE_MACOSX=yes/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/macosx
INSTALL_DIRS=		${WRKSRC}/src/plugins/macosx

BUILDLINK_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
