# $NetBSD: buildlink3.mk,v 1.2 2006/07/08 22:39:01 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTUNEPIMP_BUILDLINK3_MK:=	${LIBTUNEPIMP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtunepimp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtunepimp}
BUILDLINK_PACKAGES+=	libtunepimp
BUILDLINK_ORDER+=	libtunepimp

.if !empty(LIBTUNEPIMP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libtunepimp+=	libtunepimp>=0.4.2
BUILDLINK_PKGSRCDIR.libtunepimp?=	../../audio/libtunepimp
.endif	# LIBTUNEPIMP_BUILDLINK3_MK

.include "../../audio/musicbrainz/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
