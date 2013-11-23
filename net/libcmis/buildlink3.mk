# $NetBSD: buildlink3.mk,v 1.1 2013/11/23 17:11:05 jaapb Exp $

BUILDLINK_TREE+=	libcmis

.if !defined(LIBCMIS_BUILDLINK3_MK)
LIBCMIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcmis+=	libcmis>=0.4.1
BUILDLINK_PKGSRCDIR.libcmis?=	../../net/libcmis

#.include "../../devel/boost-headers/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/cppunit/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"
.endif	# LIBCMIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcmis
