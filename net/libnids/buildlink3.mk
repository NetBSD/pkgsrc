# $NetBSD: buildlink3.mk,v 1.14 2020/03/08 16:48:03 wiz Exp $

BUILDLINK_TREE+=	libnids

.if !defined(LIBNIDS_BUILDLINK3_MK)
LIBNIDS_BUILDLINK3_MK:=


BUILDLINK_API_DEPENDS.libnids+=	libnids>=1.24
BUILDLINK_ABI_DEPENDS.libnids?=	libnids>=1.24nb1
BUILDLINK_PKGSRCDIR.libnids?=	../../net/libnids
BUILDLINK_DEPMETHOD.libnids?=	build

pkgbase := libnids
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.libnids:Mglib)
.include "../../devel/glib2/buildlink3.mk"
# This is needed because libnids is a static library
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib	\
		  -lglib-2.0 -lgthread-2.0
.endif

.endif # LIBNIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnids
