# $NetBSD: buildlink2.mk,v 1.7 2002/09/22 09:52:34 jlam Exp $
#
# This Makefile fragment is included by packages that use GConf2.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(GCONF2_BUILDLINK2_MK)
GCONF2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			GConf2
BUILDLINK_DEPENDS.GConf2?=		GConf2>=1.2.1nb2
BUILDLINK_PKGSRCDIR.GConf2?=		../../devel/GConf2

EVAL_PREFIX+=	BUILDLINK_PREFIX.GConf2=GConf2
BUILDLINK_PREFIX.GConf2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-changeset.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-client.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-engine.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-enum-types.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-error.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-listeners.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-schema.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf-value.h
BUILDLINK_FILES.GConf2+=	include/gconf/2/gconf/gconf.h
BUILDLINK_FILES.GConf2+=	lib/GConf/2/libgconfbackend-xml.*
BUILDLINK_FILES.GConf2+=	lib/libgconf-2.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/ptl2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../net/linc/buildlink2.mk"
.include "../../textproc/gtk-doc/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	GConf2-buildlink

GConf2-buildlink: _BUILDLINK_USE

.endif	# GCONF2_BUILDLINK2_MK
