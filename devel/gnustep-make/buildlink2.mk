# $NetBSD: buildlink2.mk,v 1.9 2004/04/10 23:31:39 rh Exp $
#

.if !defined(GNUSTEP_MAKE_BUILDLINK2_MK)
GNUSTEP_MAKE_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=			gnustep-make
BUILDLINK_DEPENDS.gnustep-make?=	gnustep-make>=1.9.1
BUILDLINK_PKGSRCDIR.gnustep-make?=	../../devel/gnustep-make

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-make=gnustep-make
BUILDLINK_PREFIX.gnustep-make_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	gnustep-make-buildlink

gnustep-make-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_MAKE_BUILDLINK2_MK
