# $NetBSD: buildlink2.mk,v 1.3 2003/09/24 12:43:57 markd Exp $
#
# This Makefile fragment is included by packages that use libmilter.
#

.if !defined(LIBMILTER_BUILDLINK2_MK)
LIBMILTER_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.libmilter?=		libmilter>=8.12.9nb1
BUILDLINK_PKGSRCDIR.libmilter?=		../../mail/libmilter

.if exists(/usr/lib/libmilter.a)
_MILTER_FILELIST!= ar t /usr/lib/libmilter.a
.  if empty(_MILTER_FILELIST:Merrstring.o)
_NEED_LIBMILTER=	YES
.  else
_NEED_LIBMILTER=	NO
.  endif
.else
_NEED_LIBMILTER=	YES
.endif

.if ${_NEED_LIBMILTER} == "YES"
BUILDLINK_PACKAGES+=		libmilter
EVAL_PREFIX+=	BUILDLINK_PREFIX.libmilter=libmilter
BUILDLINK_PREFIX.libmilter_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.libmilter=	/usr
.endif

BUILDLINK_FILES.libmilter+=	include/libmilter/mfapi.h
BUILDLINK_FILES.libmilter+=	include/libmilter/mfdef.h
BUILDLINK_FILES.libmilter+=	lib/libmilter.*

BUILDLINK_TARGETS+=	libmilter-buildlink

libmilter-buildlink: _BUILDLINK_USE

.endif	# LIBMILTER_BUILDLINK2_MK
