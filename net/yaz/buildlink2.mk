# $NetBSD: buildlink2.mk,v 1.1 2003/05/16 12:41:44 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use yaz.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(YAZ_BUILDLINK2_MK)
YAZ_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		yaz
BUILDLINK_DEPENDS.yaz?=		yaz>=2.0
BUILDLINK_PKGSRCDIR.yaz?=	../../net/yaz

EVAL_PREFIX+=	BUILDLINK_PREFIX.yaz=yaz
BUILDLINK_PREFIX.yaz_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.yaz+=	include/yaz/*.h
BUILDLINK_FILES.yaz+=	lib/libyaz.*
BUILDLINK_FILES.yaz+=	lib/libyazmalloc.*

BUILDLINK_TARGETS+=	yaz-buildlink

yaz-buildlink: _BUILDLINK_USE

.endif	# YAZ_BUILDLINK2_MK
