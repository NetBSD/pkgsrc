# $NetBSD: buildlink2.mk,v 1.7 2004/04/10 23:52:37 rh Exp $
#
# This Makefile fragment is included by packages that use Pantomime.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(PANTOMIME_BUILDLINK2_MK)
PANTOMIME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Pantomime
BUILDLINK_DEPENDS.Pantomime?=		Pantomime>=1.1.2
BUILDLINK_PKGSRCDIR.Pantomime?=		../../mail/Pantomime

EVAL_PREFIX+=	BUILDLINK_PREFIX.Pantomime=Pantomime
BUILDLINK_PREFIX.Pantomime_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Library/Headers/Pantomime//*.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Library/Libraries/libPantomime.*

.include "../../x11/gnustep-back/buildlink2.mk"

BUILDLINK_TARGETS+=	Pantomime-buildlink

Pantomime-buildlink: _BUILDLINK_USE

.endif	# PANTOMIME_BUILDLINK2_MK
