# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/12 21:41:58 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTUNEPIMP_BUILDLINK3_MK:=	${LIBTUNEPIMP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtunepimp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtunepimp}
BUILDLINK_PACKAGES+=	libtunepimp

.if !empty(LIBTUNEPIMP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libtunepimp+=	libtunepimp>=0.4.2
BUILDLINK_PKGSRCDIR.libtunepimp?=	../../audio/libtunepimp
.endif	# LIBTUNEPIMP_BUILDLINK3_MK

.include "../../audio/musicbrainz/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
