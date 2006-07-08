# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:57 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSPF_ALT_BUILDLINK3_MK:=	${LIBSPF_ALT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libspf_alt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibspf_alt}
BUILDLINK_PACKAGES+=	libspf_alt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libspf_alt

.if !empty(LIBSPF_ALT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libspf_alt+=	libspf_alt>=0.4.0nb1
BUILDLINK_ABI_DEPENDS.libspf_alt+=	libspf_alt>=0.4.0nb3
BUILDLINK_PKGSRCDIR.libspf_alt?=	../../mail/libspf-alt
.endif	# LIBSPF_ALT_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/bind9/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
