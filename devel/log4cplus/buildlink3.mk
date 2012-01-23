# $NetBSD: buildlink3.mk,v 1.1 2012/01/23 11:50:38 pettai Exp $

BUILDLINK_TREE+=	log4cplus

.if !defined(LOG4CPLUS_BUILDLINK3_MK)
LOG4CPLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.log4cplus+=	log4cplus>=1.0.4
BUILDLINK_PKGSRCDIR.log4cplus?=	../../devel/log4cplus
.endif	# LOG4CPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-log4cplus
