# $NetBSD: buildlink3.mk,v 1.14 2020/05/22 12:43:52 adam Exp $

BUILDLINK_TREE+=	libdvdread

.if !defined(LIBDVDREAD_BUILDLINK3_MK)
LIBDVDREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdread+=	libdvdread>=4.1.3nb1
BUILDLINK_ABI_DEPENDS.libdvdread+=	libdvdread>=6.1.1nb1
BUILDLINK_PKGSRCDIR.libdvdread?=	../../multimedia/libdvdread

pkgbase := libdvdread
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libdvdread:Mdvdcss)
.include "../../multimedia/libdvdcss/buildlink3.mk"
.endif
.endif # LIBDVDREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdread
