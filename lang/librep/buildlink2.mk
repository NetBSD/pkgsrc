# $NetBSD: buildlink2.mk,v 1.4 2003/02/21 12:53:23 mycroft Exp $
#

.if !defined(LIBREP_BUILDLINK2_MK)
LIBREP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			librep
BUILDLINK_DEPENDS.librep?=		librep>=0.16.1
BUILDLINK_PKGSRCDIR.librep?=		../../lang/librep

EVAL_PREFIX+=	BUILDLINK_PREFIX.librep=librep
BUILDLINK_PREFIX.librep_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.librep+=	include/rep.h
BUILDLINK_FILES.librep+=	include/rep_lisp.h
BUILDLINK_FILES.librep+=	include/rep_regexp.h
BUILDLINK_FILES.librep+=	include/rep_subrs.h
BUILDLINK_FILES.librep+=	lib/librep.*
BUILDLINK_FILES.librep+=	libexec/rep/${MACHINE_GNU_PLATFORM}/rep_config.h

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"

BUILDLINK_TARGETS+=	librep-buildlink

librep-buildlink: _BUILDLINK_USE

.endif	# LIBREP_BUILDLINK2_MK
