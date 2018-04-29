# $NetBSD: buildlink3.mk,v 1.1 2018/04/29 05:11:00 wiz Exp $

BUILDLINK_TREE+=	spidermonkey52

.if !defined(SPIDERMONKEY52_BUILDLINK3_MK)
SPIDERMONKEY52_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spidermonkey52+=	spidermonkey52>=52.0.0
BUILDLINK_PKGSRCDIR.spidermonkey52?=	../../lang/spidermonkey52

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# SPIDERMONKEY52_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey52
