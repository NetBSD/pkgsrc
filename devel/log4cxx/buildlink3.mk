# $NetBSD: buildlink3.mk,v 1.1 2024/04/30 20:39:04 wiz Exp $

BUILDLINK_TREE+=	log4cxx

.if !defined(LOG4CXX_BUILDLINK3_MK)
LOG4CXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.log4cxx+=	log4cxx>=0.10.0nb8
BUILDLINK_PKGSRCDIR.log4cxx?=	../../devel/log4cxx

#.include "../../devel/apr/buildlink3.mk"
#.include "../../devel/apr-util/buildlink3.mk"
.endif	# LOG4CXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-log4cxx
