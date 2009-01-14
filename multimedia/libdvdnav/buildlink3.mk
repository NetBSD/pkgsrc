# $NetBSD: buildlink3.mk,v 1.8 2009/01/14 22:36:11 jmcneill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBDVDNAV_BUILDLINK3_MK:=	${LIBDVDNAV_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdvdnav
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdvdnav}
BUILDLINK_PACKAGES+=	libdvdnav
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libdvdnav

.if !empty(LIBDVDNAV_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libdvdnav+=	libdvdnav>=4.1.3
BUILDLINK_ABI_DEPENDS.libdvdnav+=	libdvdnav>=4.1.3
BUILDLINK_PKGSRCDIR.libdvdnav?=	../../multimedia/libdvdnav
.endif	# LIBDVDNAV_BUILDLINK3_MK

.include "../../multimedia/libdvdread/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
