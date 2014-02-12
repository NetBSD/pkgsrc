# $NetBSD: buildlink3.mk,v 1.18 2014/02/12 23:17:36 tron Exp $

BUILDLINK_TREE+=	jabberd

.if !defined(JABBERD_BUILDLINK3_MK)
JABBERD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jabberd+=	jabberd>=1.4.2
BUILDLINK_ABI_DEPENDS.jabberd+=	jabberd>=1.4.2nb12
BUILDLINK_PKGSRCDIR.jabberd?=	../../chat/jabberd

.include "../../security/openssl/buildlink3.mk"
.endif # JABBERD_BUILDLINK3_MK

BUILDLINK_TREE+=	-jabberd
