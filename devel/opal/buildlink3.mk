# $NetBSD: buildlink3.mk,v 1.5 2009/09/08 09:49:31 wiz Exp $

BUILDLINK_TREE+=	opal

.if !defined(OPAL_BUILDLINK3_MK)
OPAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opal+=	opal>=3.6.1
BUILDLINK_ABI_DEPENDS.opal?=	opal>=3.6.1
BUILDLINK_PKGSRCDIR.opal?=	../../devel/opal

.include "../../audio/speex/buildlink3.mk"
.include "../../devel/ptlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-opal
