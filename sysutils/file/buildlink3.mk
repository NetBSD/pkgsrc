# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:31 rillig Exp $
#

BUILDLINK_TREE+=	file

.if !defined(FILE_BUILDLINK3_MK)
FILE_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.file+=	file>=4.17
BUILDLINK_ABI_DEPENDS.file+=	file>=4.17
BUILDLINK_PKGSRCDIR.file?=	../../sysutils/file
pkgbase := file
.include "../../mk/pkg-build-options.mk"
.endif # FILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-file
