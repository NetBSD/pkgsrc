# $NetBSD: buildlink2.mk,v 1.7 2003/11/12 01:31:47 salo Exp $

.if !defined(BONOBO_BUILDLINK2_MK)
BONOBO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		bonobo
BUILDLINK_DEPENDS.bonobo?=	bonobo>=1.0.18nb6
BUILDLINK_PKGSRCDIR.bonobo?=	../../devel/bonobo

EVAL_PREFIX+=			BUILDLINK_PREFIX.bonobo=bonobo
BUILDLINK_PREFIX.bonobo_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.bonobo+=	include/efs*
BUILDLINK_FILES.bonobo+=	include/gnome-1.0/bonobo.h
BUILDLINK_FILES.bonobo+=	include/gnome-1.0/bonobo/*
BUILDLINK_FILES.bonobo+=	lib/bonobo/*/*
BUILDLINK_FILES.bonobo+=	lib/libbonobo.*
BUILDLINK_FILES.bonobo+=	lib/libbonobox.*
BUILDLINK_FILES.bonobo+=	lib/libbonobo-print.*
BUILDLINK_FILES.bonobo+=	lib/libefs.*
BUILDLINK_FILES.bonobo+=	share/idl/Bonobo*.idl

BUILDLINK_CPPFLAGS.bonobo=	-I${BUILDLINK_PREFIX.bonobo}/include/gnome-1.0
CPPFLAGS+=			${BUILDLINK_CPPFLAGS.bonobo}

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"

BUILDLINK_TARGETS+=	bonobo-buildlink

bonobo-buildlink: _BUILDLINK_USE

.endif	# BONOBO_BUILDLINK2_MK
