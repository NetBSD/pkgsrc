# $NetBSD: buildlink3.mk,v 1.1 2004/01/11 18:47:34 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBAO_BUILDLINK3_MK:=	${LIBAO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libao
.endif

.if !empty(LIBAO_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libao
BUILDLINK_DEPENDS.libao?=	libao>=0.8.4
BUILDLINK_PKGSRCDIR.libao?=	../../audio/libao

.  include "../../devel/pkgconfig/buildlink3.mk"
.endif	# LIBAO_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
