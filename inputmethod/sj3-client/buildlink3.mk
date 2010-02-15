# $NetBSD: buildlink3.mk,v 1.1 2010/02/15 13:35:21 obache Exp $
#

BUILDLINK_TREE+=	sj3-client

.if !defined(SJ3_CLIENT_BUILDLINK3_MK)
SJ3_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sj3-client+=	sj3-client>=2.0.1.23
BUILDLINK_PKGSRCDIR.sj3-client?=	../../inputmethod/sj3-client
.endif # SJ3_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sj3-client
