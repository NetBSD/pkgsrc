# $NetBSD: buildlink2.mk,v 1.2 2002/12/01 21:57:06 gson Exp $
#

.if !defined(TCL_SNACK_BUILDLINK2_MK)
TCL_SNACK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			tcl-snack
BUILDLINK_DEPENDS.tcl-snack?=		tcl-snack>=2.2
BUILDLINK_PKGSRCDIR.tcl-snack?=		../../audio/tcl-snack

EVAL_PREFIX+=	BUILDLINK_PREFIX.tcl-snack=tcl-snack
BUILDLINK_PREFIX.tcl-snack_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl-snack+=	lib/libsnackstub2.2.*
BUILDLINK_FILES.tcl-snack+=	lib/snack2.2/libsnack.*
BUILDLINK_FILES.tcl-snack+=	lib/snack2.2/libsound.*
BUILDLINK_FILES.tcl-snack+=	lib/snack2.2/pkgIndex.tcl
BUILDLINK_FILES.tcl-snack+=	lib/snack2.2/snack.tcl

BUILDLINK_TARGETS+=	tcl-snack-buildlink

tcl-snack-buildlink: _BUILDLINK_USE

.endif	# TCL_SNACK_BUILDLINK2_MK
