# $NetBSD: buildlink3.mk,v 1.4 2004/03/18 09:12:08 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMIKMOD_BUILDLINK3_MK:=	${LIBMIKMOD_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmikmod
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmikmod}
BUILDLINK_PACKAGES+=	libmikmod

.if !empty(LIBMIKMOD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmikmod+=	libmikmod>=3.1.9
BUILDLINK_PKGSRCDIR.libmikmod?=	../../audio/libmikmod
.endif	# LIBMIKMOD_BUILDLINK3_MK

.if defined(USE_ESOUND) && !empty(USE_ESOUND:M[Yy][Ee][Ss])
.  include "../../audio/esound/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
