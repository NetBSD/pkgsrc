# $NetBSD: hacks.mk,v 1.2 2023/07/29 09:49:47 nia Exp $

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-8*) || \
    !empty(CC_VERSION:Mgcc-7*)
# It has mechanisms for adding libstdc++fs that appear broken,
# and produces libraries with undefined symbols.
PKG_HACKS+=		EXIV2_STDCXXFS
LIBSTDCXXFS=		-lstdc++fs
LDFLAGS+=		${LIBSTDCXXFS}
.else
LIBSTDCXXFS=
.endif

SUBST_CLASSES+=		fslib
SUBST_STAGE.fslib=	pre-configure
SUBST_FILES.fslib=	cmake/exiv2.pc.in
SUBST_VARS.fslib=	LIBSTDCXXFS
