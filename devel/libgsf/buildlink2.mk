# $NetBSD: buildlink2.mk,v 1.4 2003/12/14 19:53:11 jmmv Exp $
#
# This Makefile fragment is included by packages that use libgsf.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBGSF_BUILDLINK2_MK)
LIBGSF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgsf
BUILDLINK_DEPENDS.libgsf?=		libgsf>=1.8.2nb3
BUILDLINK_PKGSRCDIR.libgsf?=		../../devel/libgsf

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgsf=libgsf
BUILDLINK_PREFIX.libgsf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgsf+=	include/libgsf-1/gsf-gnome/*
BUILDLINK_FILES.libgsf+=	include/libgsf-1/gsf/*
BUILDLINK_FILES.libgsf+=	lib/libgsf-1.*
BUILDLINK_FILES.libgsf+=	lib/libgsf-gnome-1.*

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgsf-buildlink

libgsf-buildlink: _BUILDLINK_USE

.endif	# LIBGSF_BUILDLINK2_MK
