# $NetBSD: buildlink3.mk,v 1.1 2004/03/19 15:59:16 uebayasi Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EB_BUILDLINK3_MK:=	${EB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neb}
BUILDLINK_PACKAGES+=	eb

.if !empty(EB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.eb+=	eb>=3.3.2nb1
BUILDLINK_PKGSRCDIR.eb?=	../../textproc/eb
.endif	# EB_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
