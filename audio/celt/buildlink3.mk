# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/03 00:44:49 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CELT_BUILDLINK3_MK:=	${CELT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	celt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncelt}
BUILDLINK_PACKAGES+=	celt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}celt

.if ${CELT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.celt+=	celt>=0.5.0
BUILDLINK_PKGSRCDIR.celt?=	../../audio/celt
pkgbase:= celt
.  include "../../mk/pkg-build-options.mk"
.endif	# CELT_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.celt:Mogg)
.  include "../../multimedia/libogg/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
