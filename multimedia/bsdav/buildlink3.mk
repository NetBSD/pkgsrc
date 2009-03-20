# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:02 joerg Exp $

BUILDLINK_TREE+=	bsdav

.if !defined(BSDAV_BUILDLINK3_MK)
BSDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bsdav+=	bsdav>=1.4
BUILDLINK_PKGSRCDIR.bsdav?=	../../multimedia/bsdav
BUILDLINK_LDADD.bsdav=		-lbsdav
BUILDLINK_FILES.bsdav= 		include/bsdav.h
LIBBSDAV?= ${BUILDLINK_LDADD.bsdav}

pkgbase := bsdav
.  include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.bsdav:Mx11)
.  include "../../x11/libXv/buildlink3.mk"
.endif
.endif # BSDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-bsdav
