# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBIDN_BUILDLINK3_MK:=	${LIBIDN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libidn
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibidn}
BUILDLINK_PACKAGES+=	libidn
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libidn

.if !empty(LIBIDN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libidn+=	libidn>=0.4.6
BUILDLINK_ABI_DEPENDS.libidn+=	libidn>=0.6.1nb1
BUILDLINK_PKGSRCDIR.libidn?=	../../devel/libidn
.endif	# LIBIDN_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
