# $NetBSD: buildlink3.mk,v 1.1 2014/06/01 13:25:55 obache Exp $
#

BUILDLINK_TREE+=	libpinyin

.if !defined(LIBPINYIN_BUILDLINK3_MK)
LIBPINYIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpinyin+=	libpinyin>=1.0.0
BUILDLINK_PKGSRCDIR.libpinyin?=	../../textproc/libpinyin

.include "../../devel/glib2/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.endif	# LIBPINYIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpinyin
