# $NetBSD: buildlink3.mk,v 1.2 2004/02/09 23:56:32 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ID3LIB_BUILDLINK3_MK:=	${ID3LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	id3lib
.endif

.if !empty(ID3LIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			id3lib
BUILDLINK_DEPENDS.id3lib+=		id3lib>=3.8.3
BUILDLINK_PKGSRCDIR.id3lib?=		../../audio/id3lib

.include "../../devel/zlib/buildlink3.mk"

.endif # ID3LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
