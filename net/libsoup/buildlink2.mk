# $NetBSD: buildlink2.mk,v 1.4 2004/04/01 18:32:03 jmmv Exp $

.if !defined(LIBSOUP_BUILDLINK2_MK)
LIBSOUP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libsoup
BUILDLINK_DEPENDS.libsoup?=		libsoup>=2.1.8
BUILDLINK_PKGSRCDIR.libsoup?=		../../net/libsoup

EVAL_PREFIX+=	BUILDLINK_PREFIX.libsoup=libsoup
BUILDLINK_PREFIX.libsoup_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/*
BUILDLINK_FILES.libsoup+=	lib/libsoup-2.0.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../security/gnutls/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	libsoup-buildlink

libsoup-buildlink: _BUILDLINK_USE

.endif	# LIBSOUP_BUILDLINK2_MK
