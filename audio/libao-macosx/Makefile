# $NetBSD: Makefile,v 1.8 2019/11/24 00:35:57 nia Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-macosx/}

COMMENT+=	(MacOS X plugin)

ONLY_FOR_PLATFORM+=	Darwin-*-*

CONFIGURE_ENV:=		${CONFIGURE_ENV:S/have_macosx=no//1}
BUILD_DIRS=		src/plugins/macosx
INSTALL_DIRS=		src/plugins/macosx

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
