# $NetBSD: buildlink3.mk,v 1.15 2024/05/02 08:10:18 cheusov Exp $

BUILDLINK_TREE+=	gdbm

.if !defined(GDBM_BUILDLINK3_MK)
GDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbm+=	gdbm>=1.8.3
BUILDLINK_ABI_DEPENDS.gdbm+=	gdbm>=1.18.1
BUILDLINK_PKGSRCDIR.gdbm?=	../../databases/gdbm

pkgbase:= gdbm
.include "../../mk/pkg-build-options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.gdbm:Mnls}
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.endif # GDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbm
