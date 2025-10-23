# $NetBSD: buildlink3.mk,v 1.5 2025/10/23 20:39:34 wiz Exp $
#

BUILDLINK_TREE+=	libpinyin

.if !defined(LIBPINYIN_BUILDLINK3_MK)
LIBPINYIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpinyin+=	libpinyin>=2.6.0
BUILDLINK_ABI_DEPENDS.libpinyin?=	libpinyin>=2.8.1nb1
BUILDLINK_PKGSRCDIR.libpinyin?=		../../textproc/libpinyin

.include "../../devel/glib2/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.endif	# LIBPINYIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpinyin
