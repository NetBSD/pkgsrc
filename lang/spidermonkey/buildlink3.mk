# $NetBSD: buildlink3.mk,v 1.8 2006/12/03 10:11:49 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SPIDERMONKEY_BUILDLINK3_MK:=	${SPIDERMONKEY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	spidermonkey
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nspidermonkey}
BUILDLINK_PACKAGES+=	spidermonkey
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}spidermonkey

.if !empty(SPIDERMONKEY_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.spidermonkey+=	spidermonkey>=1.5
BUILDLINK_ABI_DEPENDS.spidermonkey?=	spidermonkey>=1.5nb6
BUILDLINK_PKGSRCDIR.spidermonkey?=	../../lang/spidermonkey
.endif	# SPIDERMONKEY_BUILDLINK3_MK

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
