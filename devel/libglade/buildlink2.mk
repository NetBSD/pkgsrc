# $NetBSD: buildlink2.mk,v 1.6 2003/05/02 11:54:35 wiz Exp $

.if !defined(LIBGLADE_BUILDLINK2_MK)
LIBGLADE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libglade
BUILDLINK_DEPENDS.libglade?=	libglade>=0.17nb3
BUILDLINK_PKGSRCDIR.libglade?=	../../devel/libglade

EVAL_PREFIX+=			BUILDLINK_PREFIX.libglade=libglade
BUILDLINK_PREFIX.libglade_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libglade=	include/libglade-1.0/glade/*
BUILDLINK_FILES.libglade+=	lib/libglade.*
BUILDLINK_FILES.libglade+=	lib/libglade-gnome.*

BUILDLINK_CPPFLAGS.libglade= \
	-I${BUILDLINK_PREFIX.libglade}/include/libglade-1.0

CPPFLAGS+=	${BUILDLINK_CPPFLAGS.libglade}

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

BUILDLINK_TARGETS+=	libglade-buildlink

libglade-buildlink: _BUILDLINK_USE

.endif	# LIBGLADE_BUILDLINK2_MK
