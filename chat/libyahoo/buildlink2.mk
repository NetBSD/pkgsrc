# $NetBSD: buildlink2.mk,v 1.5 2002/09/23 09:22:14 jlam Exp $

.if !defined(LIBYAHOO_BUILDLINK2_MK)
LIBYAHOO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libyahoo
BUILDLINK_DEPENDS.libyahoo?=	libyahoo>=0.18.4
BUILDLINK_PKGSRCDIR.libyahoo?=	../../chat/libyahoo

EVAL_PREFIX+=				BUILDLINK_PREFIX.libyahoo=libyahoo
BUILDLINK_PREFIX.libyahoo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libyahoo=		include/libyahoo/*.h
BUILDLINK_FILES.libyahoo+=		lib/libyahoo.*

BUILDLINK_CPPFLAGS.libyahoo=	-I${BUILDLINK_PREFIX.libyahoo}/include/libyahoo
CPPFLAGS+=			${BUILDLINK_CPPFLAGS.libyahoo}

BUILDLINK_TARGETS+=	libyahoo-buildlink

libyahoo-buildlink: _BUILDLINK_USE

.endif	# LIBYAHOO_BUILDLINK2_MK
