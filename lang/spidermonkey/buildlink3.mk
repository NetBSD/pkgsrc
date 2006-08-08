# $NetBSD: buildlink3.mk,v 1.7 2006/08/08 21:08:14 tron Exp $

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
.if ${OPSYS} == "Darwin"
BUILDLINK_ABI_DEPENDS.spidermonkey?=	spidermonkey>=1.5nb4
.else
BUILDLINK_ABI_DEPENDS.spidermonkey?=	spidermonkey>=1.5nb1
.endif
BUILDLINK_PKGSRCDIR.spidermonkey?=	../../lang/spidermonkey
.endif	# SPIDERMONKEY_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
