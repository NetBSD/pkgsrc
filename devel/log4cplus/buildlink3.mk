# $NetBSD: buildlink3.mk,v 1.7 2025/10/19 13:43:08 adam Exp $

BUILDLINK_TREE+=	log4cplus

.if !defined(LOG4CPLUS_BUILDLINK3_MK)
LOG4CPLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.log4cplus+=	log4cplus>=2.0.3
BUILDLINK_ABI_DEPENDS.log4cplus+=	log4cplus>=2.0.3nb1
BUILDLINK_PKGSRCDIR.log4cplus?=		../../devel/log4cplus

.include "../../converters/libiconv/buildlink3.mk"
.endif	# LOG4CPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-log4cplus
