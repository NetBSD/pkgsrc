# $NetBSD: buildlink3.mk,v 1.30 2017/01/01 15:32:47 adam Exp $

BUILDLINK_TREE+=	boost-jam

.if !defined(BOOST_JAM_BUILDLINK3_MK)
BOOST_JAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boost-jam+=	boost-jam-1.63.*
BUILDLINK_DEPMETHOD.boost-jam?=		build
BUILDLINK_PKGSRCDIR.boost-jam?=		../../devel/boost-jam
.endif # BOOST_JAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-jam
