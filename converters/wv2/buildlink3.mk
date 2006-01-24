# $NetBSD: buildlink3.mk,v 1.5 2006/01/24 07:31:59 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WV2_BUILDLINK3_MK:=	${WV2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wv2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwv2}
BUILDLINK_PACKAGES+=	wv2

.if !empty(WV2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wv2?=		wv2>=0.2.2nb1
BUILDLINK_RECOMMENDED.wv2?=	wv2>=0.2.2nb3
BUILDLINK_PKGSRCDIR.wv2?=	../../converters/wv2
.endif	# WV2_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
