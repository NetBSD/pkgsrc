# $NetBSD: buildlink3.mk,v 1.9 2008/01/18 05:06:20 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTUNEPIMP_BUILDLINK3_MK:=	${LIBTUNEPIMP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libtunepimp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtunepimp}
BUILDLINK_PACKAGES+=	libtunepimp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libtunepimp

.if ${LIBTUNEPIMP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libtunepimp+=	libtunepimp>=0.5.0
BUILDLINK_ABI_DEPENDS.libtunepimp?=	libtunepimp>=0.5.3nb4
BUILDLINK_PKGSRCDIR.libtunepimp?=	../../audio/libtunepimp
.endif	# LIBTUNEPIMP_BUILDLINK3_MK

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
