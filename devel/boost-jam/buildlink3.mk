# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:24:10 joerg Exp $

BUILDLINK_TREE+=	boost-jam

.if !defined(BOOST_JAM_BUILDLINK3_MK)
BOOST_JAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boost-jam+=		boost-jam-1.38.*
BUILDLINK_DEPMETHOD.boost-jam?=	build
BUILDLINK_PKGSRCDIR.boost-jam?=	../../devel/boost-jam
.endif # BOOST_JAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-jam
