# $NetBSD: buildlink3.mk,v 1.9 2013/02/06 23:21:30 jperkin Exp $

BUILDLINK_TREE+=	opal

.if !defined(OPAL_BUILDLINK3_MK)
OPAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opal+=	opal>=3.6.1
BUILDLINK_ABI_DEPENDS.opal+=	opal>=3.6.6nb6
BUILDLINK_PKGSRCDIR.opal?=	../../devel/opal

.include "../../audio/speex/buildlink3.mk"
.include "../../devel/ptlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-opal
