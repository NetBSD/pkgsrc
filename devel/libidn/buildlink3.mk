# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 10:22:03 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBIDN_BUILDLINK3_MK:=	${LIBIDN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libidn
.endif

.if !empty(LIBIDN_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libidn
BUILDLINK_DEPENDS.libidn+=	libidn>=0.3.3
BUILDLINK_PKGSRCDIR.libidn?=	../../devel/libidn

.  include "../../converters/libiconv/buildlink3.mk"
.  include "../../devel/libgetopt/buildlink3.mk"
.endif # LIBIDN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
