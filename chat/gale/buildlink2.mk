# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:03:59 jlam Exp $

.if !defined(GALE_BUILDLINK2_MK)
GALE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gale
BUILDLINK_DEPENDS.gale?=	gale>=0.99
BUILDLINK_PKGSRCDIR.gale?=	../../chat/gale

EVAL_PREFIX+=			BUILDLINK_PREFIX.gale=gale
BUILDLINK_PREFIX.gale_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gale=		include/gale/*.h
BUILDLINK_FILES.gale+=		include/oop-adns.h
BUILDLINK_FILES.gale+=		include/oop-glib.h
BUILDLINK_FILES.gale+=		include/oop-www.h
BUILDLINK_FILES.gale+=		include/oop.h
BUILDLINK_FILES.gale+=		lib/libgale.*
BUILDLINK_FILES.gale+=		lib/liboop-adns.*
BUILDLINK_FILES.gale+=		lib/liboop-glib.*
BUILDLINK_FILES.gale+=		lib/liboop-www.*
BUILDLINK_FILES.gale+=		lib/liboop.*

.include "../../devel/glib/buildlink2.mk"
.include "../../net/adns/buildlink2.mk"
.include "../../security/rsaref/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"

BUILDLINK_TARGETS+=		gale-buildlink

gale-buildlink: _BUILDLINK_USE

.endif	# GALE_BUILDLINK2_MK
