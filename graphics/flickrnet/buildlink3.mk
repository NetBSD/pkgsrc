# $NetBSD: buildlink3.mk,v 1.1 2015/05/23 09:01:20 kefren Exp $

BUILDLINK_TREE+=	flickrnet

.if !defined(FLICKRNET_BUILDLINK3_MK)
FLICKRNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flickrnet+=	flickrnet>=3.16
BUILDLINK_PKGSRCDIR.flickrnet?=	../../graphics/flickrnet
BUILDLINK_CONTENTS_FILTER.flickrnet=	${EGREP} '(^lib/)'

.endif	# FLICKRNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-flickrnet
