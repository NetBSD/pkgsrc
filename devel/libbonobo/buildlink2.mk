# $NetBSD: buildlink2.mk,v 1.8 2003/11/12 01:31:48 salo Exp $

.if !defined(LIBBONOBO_BUILDLINK2_MK)
LIBBONOBO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libbonobo
BUILDLINK_DEPENDS.libbonobo?=	libbonobo>=2.2.0nb4
BUILDLINK_PKGSRCDIR.libbonobo?=	../../devel/libbonobo

EVAL_PREFIX+=	BUILDLINK_PREFIX.libbonobo=libbonobo
BUILDLINK_PREFIX.libbonobo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libbonobo+=	include/libbonobo-2.0/bonobo/*
BUILDLINK_FILES.libbonobo+=	include/libbonobo-2.0/*
BUILDLINK_FILES.libbonobo+=	lib/bonobo/monikers/*
BUILDLINK_FILES.libbonobo+=	lib/bonobo/servers/*
BUILDLINK_FILES.libbonobo+=	lib/libbonobo-2.*
BUILDLINK_FILES.libbonobo+=	lib/orbit-2.0/Bonobo_module.*
BUILDLINK_FILES.libbonobo+=	lib/pkgconfig/libbonobo-2.0.pc
BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-2.0/*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"

BUILDLINK_TARGETS+=	libbonobo-buildlink

libbonobo-buildlink: _BUILDLINK_USE

.endif	# LIBBONOBO_BUILDLINK2_MK
