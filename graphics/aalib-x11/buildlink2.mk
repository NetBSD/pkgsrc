# $NetBSD: buildlink2.mk,v 1.3 2002/08/26 19:38:06 jlam Exp $

.if !defined(AALIB_X11_BUILDLINK2_MK)
AALIB_X11_BUILDLINK2_MK= # defined

BUILDLINK_PACKAGES+=		aalib-x11
BUILDLINK_DEPENDS.aalib-x11?=	aalib-x11>=1.4.0.4nb1
BUILDLINK_PKGSRCDIR.aalib-x11?=	../../graphics/aalib-x11

EVAL_PREFIX+=	BUILDLINK_PREFIX.aalib-x11=aalib-x11
BUILDLINK_PREFIX.aalib-x11_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.aalib-x11=	include/aalib-x11.h
BUILDLINK_FILES.aalib-x11+=	lib/libaa-x11.*
BUILDLINK_TRANSFORM.aalib-x11+=	-e "s|/aalib-x11.h|/aalib.h|g"
BUILDLINK_TRANSFORM+=		l:aa:aa-x11

AALIB_CONFIG=		${BUILDLINK_PREFIX.aalib-x11}/bin/aalib-x11-config
CONFIGURE_ENV+=		AALIB_CONFIG="${AALIB_CONFIG}"
MAKE_ENV+=		AALIB_CONFIG="${AALIB_CONFIG}"

BUILDLINK_TARGETS+=	aalib-x11-buildlink

aalib-x11-buildlink: _BUILDLINK_USE

.endif # AALIB_X11_BUILDLINK2_MK
