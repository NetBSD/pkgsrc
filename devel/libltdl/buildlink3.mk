# $NetBSD: buildlink3.mk,v 1.11 2013/04/12 13:44:07 joerg Exp $

BUILDLINK_TREE+=	libltdl

.if !defined(LIBLTDL_BUILDLINK3_MK)
LIBLTDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libltdl+=	libltdl>=2.4.2
BUILDLINK_ABI_DEPENDS.libltdl+=	libltdl>=2.2.6
BUILDLINK_PKGSRCDIR.libltdl?=	../../devel/libltdl

.include "../../mk/dlopen.buildlink3.mk"
.endif # LIBLTDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libltdl
