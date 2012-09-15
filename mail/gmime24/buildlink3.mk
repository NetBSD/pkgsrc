# $NetBSD: buildlink3.mk,v 1.7 2012/09/15 10:05:27 obache Exp $

BUILDLINK_TREE+=	gmime24

.if !defined(GMIME24_BUILDLINK3_MK)
GMIME24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime24+=	gmime24>=2.4.3
BUILDLINK_ABI_DEPENDS.gmime24+=	gmime24>=2.4.32nb1
BUILDLINK_PKGSRCDIR.gmime24?=	../../mail/gmime24

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # GMIME24_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime24
