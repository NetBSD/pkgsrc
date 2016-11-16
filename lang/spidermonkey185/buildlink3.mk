# $NetBSD: buildlink3.mk,v 1.1 2016/11/16 13:13:43 fhajny Exp $

BUILDLINK_TREE+=	spidermonkey185

.if !defined(SPIDERMONKEY185_BUILDLINK3_MK)
SPIDERMONKEY185_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spidermonkey185+=	spidermonkey185>=1.0.0
BUILDLINK_PKGSRCDIR.spidermonkey185?=	../../lang/spidermonkey185

.include "../../devel/nspr/buildlink3.mk"
.endif	# SPIDERMONKEY185_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey185
