# $NetBSD: buildlink2.mk,v 1.1.2.4 2002/08/22 19:48:44 jlam Exp $

.if !defined(ZLIB_BUILDLINK2_MK)
ZLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.zlib?=	zlib>=1.1.3
BUILDLINK_PKGSRCDIR.zlib?=	../../devel/zlib

.if defined(USE_ZLIB)
_NEED_ZLIB=		YES
.else
.  if exists(/usr/include/zlib.h)
_NEED_ZLIB=		NO
.  else
_NEED_ZLIB=		YES
.  endif
#
# Solaris has a broken (for the purposes of pkgsrc) version of zlib.
#
_INCOMPAT_ZLIB=		SunOS-*-*

#
# Some NetBSD versions shipped with versions lower than 1.1.3.
#
_INCOMPAT_ZLIB+=	NetBSD-0.*-* NetBSD-1.[012]*-*
_INCOMPAT_ZLIB+=	NetBSD-1.3-* NetBSD-1.3.*-* NetBSD-1.3[A-H]-*

INCOMPAT_ZLIB?=		# empty
.  for _pattern_ in ${_INCOMPAT_ZLIB} ${INCOMPAT_ZLIB}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_ZLIB=		YES
.    endif
.  endfor
.endif

.if ${_NEED_ZLIB} == "YES"
BUILDLINK_PACKAGES+=		zlib
EVAL_PREFIX+=	BUILDLINK_PREFIX.zlib=zlib
BUILDLINK_PREFIX.zlib_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.zlib=		/usr
.endif

BUILDLINK_FILES.zlib=	include/zconf.h
BUILDLINK_FILES.zlib+=	include/zlib.h
BUILDLINK_FILES.zlib+=	lib/libz.*

BUILDLINK_TARGETS+=	zlib-buildlink

.if ${_NEED_ZLIB} == "NO"
LIBTOOL_ARCHIVE_UNTRANSFORM_SED+= \
	-e "s|${LOCALBASE}/lib/libz.la|-L${BUILDLINK_PREFIX.zlib}/lib -lz|g"
.endif

zlib-buildlink: _BUILDLINK_USE

.endif	# ZLIB_BUILDLINK2_MK
