# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/08/03 15:47:46 jmmv Exp $
#
# This Makefile fragment is included by packages that use beecrypt.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(BEECRYPT_BUILDLINK2_MK)
BEECRYPT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			beecrypt
BUILDLINK_DEPENDS.beecrypt?=		beecrypt>=2.1.0
BUILDLINK_PKGSRCDIR.beecrypt?=		../../devel/beecrypt

EVAL_PREFIX+=	BUILDLINK_PREFIX.beecrypt=beecrypt
BUILDLINK_PREFIX.beecrypt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.beecrypt+=	include/beecrypt/*
BUILDLINK_FILES.beecrypt+=	lib/libbeecrypt.*

BUILDLINK_TARGETS+=	beecrypt-buildlink

beecrypt-buildlink: _BUILDLINK_USE

.endif	# BEECRYPT_BUILDLINK2_MK
