# $NetBSD: hacks.mk,v 1.1 2023/07/29 07:15:18 nia Exp $

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-8*) || \
    !empty(CC_VERSION:Mgcc-7*)
# It has mechanisms for adding libstdc++fs that appear broken,
# and produces libraries with undefined symbols.
PKG_HACKS+=		EXIV2_STDCXXFS
LIBSTDCXXFS=		-lstdc++fs
LDFLAGS+=		${LIBSTDCXXFS}
SUBST_CLASSES+=		fslib
SUBST_STAGE.fslib=	pre-configure
SUBST_FILES.fslib=	cmake/exiv2.pc.in
SUBST_VARS.fslib=	LIBSTDCXXFS
.endif
