# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:08:47 jlam Exp $
#
# This Makefile fragment is included by packages that use bzip2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.bzip2 to the dependency pattern
#     for the version of bzip2 desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(BZIP2_BUILDLINK2_MK)
BZIP2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.bzip2?=	bzip2>=1.0.1

.if exists(/usr/include/bzlib.h)
#
# Recent versions of the libbz2 API prefix all functions with "BZ2_".
#
_BUILTIN_BZIP2!=	${EGREP} -c "BZ2_" /usr/include/bzlib.h || ${TRUE}
.else
_BUILTIN_BZIP2!=	0
.endif

.if ${_BUILTIN_BZIP2} == "0"
_NEED_BZIP2=		YES
.else
_NEED_BZIP2=		NO
.endif

.if ${_NEED_BZIP2} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.bzip2}:../../archivers/bzip2
BUILDLINK_PREFIX.bzip2=	${LOCALBASE}
.else
BUILDLINK_PREFIX.bzip2=	/usr
.endif

BUILDLINK_FILES.bzip2=		include/bzlib.h
BUILDLINK_FILES.bzip2+=		lib/libbz2.*

BUILDLINK_TARGETS+=		bzip2-buildlink

bzip2-buildlink: _BUILDLINK_USE

.endif	# BZIP2_BUILDLINK2_MK
