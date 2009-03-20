# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:29 joerg Exp $
#

BUILDLINK_TREE+=	silc-toolkit

.if !defined(SILC_TOOLKIT_BUILDLINK3_MK)
SILC_TOOLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.silc-toolkit+=	silc-toolkit>=0.9.12
BUILDLINK_ABI_DEPENDS.silc-toolkit+=	silc-toolkit>=0.9.12nb1
BUILDLINK_PKGSRCDIR.silc-toolkit?=	../../devel/silc-toolkit

.include "../../devel/libgetopt/buildlink3.mk"
.endif # SILC_TOOLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-silc-toolkit
