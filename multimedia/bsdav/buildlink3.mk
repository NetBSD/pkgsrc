# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/01/30 19:21:08 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BSDAV_BUILDLINK3_MK:=	${BSDAV_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	bsdav
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nbsdav}
BUILDLINK_PACKAGES+=	bsdav
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}bsdav

.if ${BSDAV_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.bsdav+=	bsdav>=1.4
BUILDLINK_PKGSRCDIR.bsdav?=	../../multimedia/bsdav
BUILDLINK_LDADD.bsdav=		-lbsdav
BUILDLINK_FILES.bsdav= 		include/bsdav.h
LIBBSDAV?= ${BUILDLINK_LDADD.bsdav}

pkgbase := bsdav
.  include "../../mk/pkg-build-options.mk"
.endif	# BSDAV_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.bsdav:Mx11)
.  include "../../x11/libXv/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
