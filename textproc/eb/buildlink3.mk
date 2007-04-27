# $NetBSD: buildlink3.mk,v 1.13 2007/04/27 04:08:19 uebayasi Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EB_BUILDLINK3_MK:=	${EB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neb}
BUILDLINK_PACKAGES+=	eb
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}eb

.if !empty(EB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.eb+=		eb>=3.3.2nb1
BUILDLINK_ABI_DEPENDS.eb+=		eb>=4.1.3nb1
BUILDLINK_PKGSRCDIR.eb?=		../../textproc/eb
.endif	# EB_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
