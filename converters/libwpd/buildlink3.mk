# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/06/26 22:08:08 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWPD_BUILDLINK3_MK:=	${LIBWPD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwpd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwpd}
BUILDLINK_PACKAGES+=	libwpd

.if !empty(LIBWPD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libwpd+=	libwpd>=0.8.1
BUILDLINK_PKGSRCDIR.libwpd?=	../../converters/libwpd
.endif	# LIBWPD_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
