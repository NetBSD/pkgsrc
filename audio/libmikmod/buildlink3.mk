# $NetBSD: buildlink3.mk,v 1.2 2004/02/19 06:41:21 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMIKMOD_BUILDLINK3_MK:=	${LIBMIKMOD_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmikmod
.endif

.if !empty(LIBMIKMOD_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libmikmod
BUILDLINK_DEPENDS.libmikmod+=	libmikmod>=3.1.9
BUILDLINK_PKGSRCDIR.libmikmod?=	../../audio/libmikmod

.  if defined(USE_ESOUND) && !empty(USE_ESOUND:M[Yy][Ee][Ss])
.    include "../../audio/esound/buildlink3.mk"
.  endif
.endif # LIBMIKMOD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
