# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:02 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBFLASH_BUILDLINK3_MK:=	${LIBFLASH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libflash
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibflash}
BUILDLINK_PACKAGES+=	libflash

.if !empty(LIBFLASH_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libflash+=	libflash>=0.4.10nb4
BUILDLINK_RECOMMENDED.libflash+=	libflash>=0.4.10nb5
BUILDLINK_PKGSRCDIR.libflash?=	../../multimedia/libflash
.endif	# LIBFLASH_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
