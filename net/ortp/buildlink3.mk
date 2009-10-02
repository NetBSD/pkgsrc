# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 19:09:29 markd Exp $

BUILDLINK_TREE+=	ortp

.if !defined(ORTP_BUILDLINK3_MK)
ORTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ortp+=	ortp>=0.13.1
BUILDLINK_PKGSRCDIR.ortp?=	../../net/ortp
.endif # ORTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ortp
