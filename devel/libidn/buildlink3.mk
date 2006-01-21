# $NetBSD: buildlink3.mk,v 1.7 2006/01/21 23:15:49 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBIDN_BUILDLINK3_MK:=	${LIBIDN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libidn
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibidn}
BUILDLINK_PACKAGES+=	libidn

.if !empty(LIBIDN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libidn+=	libidn>=0.4.6
BUILDLINK_RECOMMENDED.libidn+=	libidn>=0.5.5nb1
BUILDLINK_PKGSRCDIR.libidn?=	../../devel/libidn
.endif	# LIBIDN_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
