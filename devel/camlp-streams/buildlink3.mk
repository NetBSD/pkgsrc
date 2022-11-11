# $NetBSD: buildlink3.mk,v 1.1 2022/11/11 10:29:10 jaapb Exp $

BUILDLINK_TREE+=	camlp-streams

.if !defined(CAMLP_STREAMS_BUILDLINK3_MK)
CAMLP_STREAMS_BUILDLINK3_MK:=


BUILDLINK_API_DEPENDS.camlp-streams+=	camlp-streams>=5.0.1
BUILDLINK_PKGSRCDIR.camlp-streams?=	../../devel/camlp-streams
.endif	# CAMLP_STREAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlp-streams
