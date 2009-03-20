# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:24 joerg Exp $
#

BUILDLINK_TREE+=	file

.if !defined(FILE_BUILDLINK3_MK)
FILE_BUILDLINK3_MK:=

.  include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.file+=	file>=4.17
BUILDLINK_ABI_DEPENDS.file+=	file>=4.17
BUILDLINK_PKGSRCDIR.file?=	../../sysutils/file
pkgbase := file
.include "../../mk/pkg-build-options.mk"
.endif # FILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-file
