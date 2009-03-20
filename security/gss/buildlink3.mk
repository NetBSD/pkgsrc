# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:17 joerg Exp $

BUILDLINK_TREE+=	gss

.if !defined(GSS_BUILDLINK3_MK)
GSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gss+=		gss>=0.0.6nb1
BUILDLINK_ABI_DEPENDS.gss+=	gss>=0.0.13nb1
BUILDLINK_PKGSRCDIR.gss?=	../../security/gss
.endif # GSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gss
