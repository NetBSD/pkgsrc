# $NetBSD: buildlink3.mk,v 1.13 2009/05/20 00:58:20 wiz Exp $

BUILDLINK_TREE+=	spidermonkey

.if !defined(SPIDERMONKEY_BUILDLINK3_MK)
SPIDERMONKEY_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.spidermonkey+=	spidermonkey>=1.5
.if ${OPSYS} == "Darwin"
BUILDLINK_ABI_DEPENDS.spidermonkey?=	spidermonkey>=1.60nb2
.else
BUILDLINK_ABI_DEPENDS.spidermonkey?=	spidermonkey>=1.5nb8
.endif
BUILDLINK_PKGSRCDIR.spidermonkey?=	../../lang/spidermonkey

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.endif # SPIDERMONKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey
