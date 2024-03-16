# $NetBSD: Makefile,v 1.10 2024/03/16 17:38:23 nia Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-macosx/}

COMMENT+=	(MacOS X plugin)

ONLY_FOR_PLATFORM+=	Darwin-*-*

BUILD_DIRS=		src/plugins/macosx
INSTALL_DIRS=		src/plugins/macosx

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100600
CPPFLAGS+=	-DAudioComponent=Component
CPPFLAGS+=	-DAudioComponentDescription=ComponentDescription
CPPFLAGS+=	-DAudioComponentFindNext=FindNextComponent
CPPFLAGS+=	-DAudioComponentInstanceNew=OpenAComponent
CPPFLAGS+=	-DAudioComponentInstanceDispose=CloseComponent
.endif

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
