# $NetBSD: buildlink3.mk,v 1.1 2020/08/02 03:13:33 tnn Exp $

BUILDLINK_TREE+=	log4cpp

.if !defined(LOG4CPP_BUILDLINK3_MK)
LOG4CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.log4cpp+=	log4cpp>=1.1.3
BUILDLINK_PKGSRCDIR.log4cpp?=	../../textproc/log4cpp
.endif	# LOG4CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-log4cpp
