# $NetBSD: buildlink3.mk,v 1.14 2011/01/01 14:03:42 wiz Exp $

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

pkgbase := spidermonkey
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.spidermonkey:Mthreads)
.  include "../../devel/nspr/buildlink3.mk"
.  include "../../mk/pthread.buildlink3.mk"
.endif
.endif # SPIDERMONKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey
