# $NetBSD: buildlink3.mk,v 1.11 2006/06/07 07:26:35 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWMF_BUILDLINK3_MK:=	${LIBWMF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwmf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwmf}
BUILDLINK_PACKAGES+=	libwmf

.if !empty(LIBWMF_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libwmf+=	libwmf>=0.2.8nb2
BUILDLINK_ABI_DEPENDS.libwmf+=	libwmf>=0.2.8.4nb3
BUILDLINK_PKGSRCDIR.libwmf?=	../../graphics/libwmf
.endif	# LIBWMF_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
