# $NetBSD: buildlink2.mk,v 1.3 2002/09/20 09:51:44 jlam Exp $

.if !defined(LIBYAHOO_BUILDLINK2_MK)
LIBYAHOO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libyahoo
BUILDLINK_DEPENDS.libyahoo?=	libyahoo>=0.18.4
BUILDLINK_PKGSRCDIR.libyahoo?=	../../chat/libyahoo

EVAL_PREFIX+=				BUILDLINK_PREFIX.libyahoo=libyahoo
BUILDLINK_PREFIX.libyahoo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libyahoo=		include/libyahoo/*.h
BUILDLINK_FILES.libyahoo+=		lib/libyahoo.a

BUILDLINK_TRANSFORM.libyahoo=	-e "s|include/libyahoo/|include/|g"

BUILDLINK_TARGETS+=	libyahoo-buildlink

libyahoo-buildlink: _BUILDLINK_USE

.endif	# LIBYAHOO_BUILDLINK2_MK
