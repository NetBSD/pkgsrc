# $NetBSD: buildlink2.mk,v 1.1 2003/07/29 16:27:26 wiz Exp $
#
# This Makefile fragment is included by packages that use inn.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(INN_BUILDLINK2_MK)
INN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			inn
BUILDLINK_DEPENDS.inn?=		inn>=2.3.4
BUILDLINK_PKGSRCDIR.inn?=		../../news/inn

EVAL_PREFIX+=	BUILDLINK_PREFIX.inn=inn
BUILDLINK_PREFIX.inn_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.inn=          inn/lib/libinn.a
BUILDLINK_FILES.inn+=         inn/lib/libstorage.a
BUILDLINK_FILES.inn+=         include/inn/*

BUILDLINK_TARGETS+=	inn-buildlink

inn-buildlink: _BUILDLINK_USE

.endif	# INN_BUILDLINK2_MK
