# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/30 03:32:19 bjs Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PAKCHOIS_BUILDLINK3_MK:=	${PAKCHOIS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pakchois
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npakchois}
BUILDLINK_PACKAGES+=	pakchois
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pakchois

.if ${PAKCHOIS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.pakchois+=	pakchois>=0.4
BUILDLINK_PKGSRCDIR.pakchois?=	../../security/pakchois
.endif	# PAKCHOIS_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
