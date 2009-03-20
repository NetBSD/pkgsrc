# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:09 joerg Exp $

BUILDLINK_TREE+=	liblive

.if !defined(LIBLIVE_BUILDLINK3_MK)
LIBLIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblive+=	liblive>=20080706
BUILDLINK_ABI_DEPENDS.liblive+=	liblive>=20080706
BUILDLINK_PKGSRCDIR.liblive?=	../../net/liblive
BUILDLINK_INCDIRS.liblive+=     include/BasicUsageEnvironment
BUILDLINK_INCDIRS.liblive+=     include/UsageEnvironment
BUILDLINK_INCDIRS.liblive+=     include/groupsock
BUILDLINK_INCDIRS.liblive+=     include/liveMedia
.endif # LIBLIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblive
