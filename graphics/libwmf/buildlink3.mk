# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 20:07:25 wiz Exp $
#
# This Makefile fragment is included by packages that use libwmf.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWMF_BUILDLINK3_MK:=	${LIBWMF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwmf
.endif

.if !empty(LIBWMF_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libwmf
BUILDLINK_DEPENDS.libwmf+=		libwmf>=0.2.8nb2
BUILDLINK_PKGSRCDIR.libwmf?=		../../graphics/libwmf

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif # LIBWMF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
