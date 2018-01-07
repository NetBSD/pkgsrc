# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:07 rillig Exp $
#

BUILDLINK_TREE+=	log4shib

.if !defined(LOG4SHIB_BUILDLINK3_MK)
LOG4SHIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.log4shib+=	log4shib>=1.0.4
BUILDLINK_PKGSRCDIR.log4shib?=		../../devel/log4shib
.endif	# LOG4SHIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-log4shib
