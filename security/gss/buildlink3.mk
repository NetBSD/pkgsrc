# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:28 rillig Exp $

BUILDLINK_TREE+=	gss

.if !defined(GSS_BUILDLINK3_MK)
GSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gss+=	gss>=0.0.6nb1
BUILDLINK_ABI_DEPENDS.gss+=	gss>=0.0.13nb1
BUILDLINK_PKGSRCDIR.gss?=	../../security/gss
.endif # GSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gss
