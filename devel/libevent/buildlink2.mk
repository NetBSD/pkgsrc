# $NetBSD: buildlink2.mk,v 1.3 2004/02/05 06:58:03 jlam Exp $
#
# This Makefile fragment is included by packages that use libevent.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBEVENT_BUILDLINK2_MK)
LIBEVENT_BUILDLINK2_MK=	# defined

.if exists(/usr/include/event.h)
_NEED_LIBEVENT=		NO
.else
_NEED_LIBEVENT=		YES
.endif

.if defined(BUILDLINK_PREFER_PKGSRC)
.  if empty(BUILDLINK_PREFER_PKGSRC) || \
      !empty(BUILDLINK_PREFER_PKGSRC:M[yY][eE][sS]) || \
      !empty(BUILDLINK_PREFER_PKGSRC:Mlibevent)
_NEED_LIBEVENT=	YES
.  endif
.endif

.if ${_NEED_LIBEVENT} == "YES"
BUILDLINK_PACKAGES+=			libevent
BUILDLINK_DEPENDS.libevent?=		libevent>=0.6
BUILDLINK_PKGSRCDIR.libevent?=		../../devel/libevent

EVAL_PREFIX+=	BUILDLINK_PREFIX.libevent=libevent
BUILDLINK_PREFIX.libevent_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.libevent=		/usr
.endif

BUILDLINK_FILES.libevent+=	include/event.h
BUILDLINK_FILES.libevent+=	lib/libevent.*

BUILDLINK_TARGETS+=	libevent-buildlink

libevent-buildlink: _BUILDLINK_USE

.endif	# LIBEVENT_BUILDLINK2_MK
