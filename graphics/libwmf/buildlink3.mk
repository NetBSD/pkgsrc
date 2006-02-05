# $NetBSD: buildlink3.mk,v 1.8 2006/02/05 23:09:35 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWMF_BUILDLINK3_MK:=	${LIBWMF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwmf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwmf}
BUILDLINK_PACKAGES+=	libwmf

.if !empty(LIBWMF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libwmf+=	libwmf>=0.2.8nb2
BUILDLINK_RECOMMENDED.libwmf+=	libwmf>=0.2.8.4nb2
BUILDLINK_PKGSRCDIR.libwmf?=	../../graphics/libwmf
.endif	# LIBWMF_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
