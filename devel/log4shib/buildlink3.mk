# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/15 08:18:53 pettai Exp $
#

BUILDLINK_TREE+=	log4shib

.if !defined(LOG4SHIB_BUILDLINK3_MK)
LOG4SHIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.log4shib+=	log4shib>=1.0.4
BUILDLINK_PKGSRCDIR.log4shib?=	../../devel/log4shib
.endif	# LOG4SHIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-log4shib
