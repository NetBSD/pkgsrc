# $NetBSD: buildlink2.mk,v 1.4 2003/05/31 08:28:34 uebayasi Exp $

.if !defined(CANNA_BUILDLINK2_MK)
CANNA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		canna
BUILDLINK_DEPENDS.canna?=	Canna-lib>=3.6p3
BUILDLINK_PKGSRCDIR.canna?=	../../inputmethod/canna-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.canna=canna-lib
BUILDLINK_PREFIX.canna_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.canna=		include/canna/RK.h
BUILDLINK_FILES.canna+=		include/canna/jrkanji.h
BUILDLINK_FILES.canna+=		include/canna/keydef.h
BUILDLINK_FILES.canna+=		include/canna/mfdef.h
BUILDLINK_FILES.canna+=		lib/libRKC.*
BUILDLINK_FILES.canna+=		lib/libRKC16.*
BUILDLINK_FILES.canna+=		lib/libcanna.*
BUILDLINK_FILES.canna+=		lib/libcanna16.*

BUILDLINK_TARGETS+=	canna-buildlink

canna-buildlink: _BUILDLINK_USE

.endif	# CANNA_BUILDLINK2_MK
