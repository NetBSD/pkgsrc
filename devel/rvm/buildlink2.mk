# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:49 jlam Exp $

.if !defined(RVM_BUILDLINK2_MK)
RVM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		rvm
BUILDLINK_DEPENDS.rvm?=		rvm>=1.3
BUILDLINK_PKGSRCDIR.rvm?=	../../devel/rvm

EVAL_PREFIX+=		BUILDLINK_PREFIX.rvm=rvm
BUILDLINK_PREFIX.rvm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rvm=	include/rvm/*
BUILDLINK_FILES.rvm+=	lib/librds.*
BUILDLINK_FILES.rvm+=	lib/librdslwp.*
BUILDLINK_FILES.rvm+=	lib/librvm.*
BUILDLINK_FILES.rvm+=	lib/librvmlwp.*
BUILDLINK_FILES.rvm+=	lib/libseg.*

.include "../../devel/lwp/buildlink2.mk"

BUILDLINK_TARGETS+=	rvm-buildlink

rvm-buildlink: _BUILDLINK_USE

.endif	# RVM_BUILDLINK2_MK
