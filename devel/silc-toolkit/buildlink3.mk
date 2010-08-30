# $NetBSD: buildlink3.mk,v 1.9 2010/08/30 11:17:16 adam Exp $
#

BUILDLINK_TREE+=	silc-toolkit

.if !defined(SILC_TOOLKIT_BUILDLINK3_MK)
SILC_TOOLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.silc-toolkit+=	silc-toolkit>=1.1.10
BUILDLINK_ABI_DEPENDS.silc-toolkit+=	silc-toolkit>=1.1.10
BUILDLINK_PKGSRCDIR.silc-toolkit?=	../../devel/silc-toolkit

.include "../../devel/libgetopt/buildlink3.mk"
.endif # SILC_TOOLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-silc-toolkit
