# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:21 joerg Exp $

BUILDLINK_TREE+=	openvas-libraries

.if !defined(OPENVAS_LIBRARIES_BUILDLINK3_MK)
OPENVAS_LIBRARIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvas-libraries+=	openvas-libraries>=2.0.0
BUILDLINK_PKGSRCDIR.openvas-libraries?=	../../security/openvas-libraries
.endif # OPENVAS_LIBRARIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvas-libraries
