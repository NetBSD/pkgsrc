# $NetBSD: buildlink2.mk,v 1.1 2003/11/07 23:07:09 reed Exp $

.if !defined(NETATALK_BUILDLINK2_MK)
NETATALK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			netatalk
BUILDLINK_DEPENDS.netatalk?=		netatalk>=1.5
BUILDLINK_PKGSRCDIR.netatalk?=		../../net/netatalk

EVAL_PREFIX+=				BUILDLINK_PREFIX.netatalk=netatalk
BUILDLINK_PREFIX.netatalk_DEFAULT= 	${LOCALBASE}
BUILDLINK_FILES.netatalk=		bin/netatalk-config
BUILDLINK_FILES.netatalk+=		include/atalk/*
BUILDLINK_FILES.netatalk+=		include/netatalk/*
BUILDLINK_FILES.netatalk+=		lib/libatalk.*

BUILDLINK_TARGETS+=			netatalk-buildlink

netatalk-buildlink: _BUILDLINK_USE

.endif	# NETATALK_BUILDLINK2_MK
