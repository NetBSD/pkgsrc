# $NetBSD: buildlink3.mk,v 1.1 2014/11/21 11:29:52 obache Exp $

BUILDLINK_TREE+=	kyotocabinet

.if !defined(KYOTOCABINET_BUILDLINK3_MK)
KYOTOCABINET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kyotocabinet+=	kyotocabinet>=1.2.72
BUILDLINK_PKGSRCDIR.kyotocabinet?=	../../databases/kyotocabinet
.endif	# KYOTOCABINET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kyotocabinet
