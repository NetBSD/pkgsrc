# $NetBSD: buildlink3.mk,v 1.7 2004/10/03 00:13:25 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ATK_BUILDLINK3_MK:=	${ATK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	atk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Natk}
BUILDLINK_PACKAGES+=	atk

.if !empty(ATK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.atk+=		atk>=1.8.0
BUILDLINK_RECOMMENDED.atk+=	atk>=1.8.0nb1
BUILDLINK_PKGSRCDIR.atk?=	../../devel/atk
.endif	# ATK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
