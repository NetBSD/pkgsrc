# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:06 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FREETYPE_BUILDLINK3_MK:=	${FREETYPE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	freetype
.endif

.if !empty(FREETYPE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		freetype
BUILDLINK_DEPENDS.freetype?=	freetype-lib>=1.3.1nb1
BUILDLINK_PKGSRCDIR.freetype?=	../../graphics/freetype-lib

.  include "../../devel/gettext-lib/buildlink3.mk"
.endif	# FREETYPE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
