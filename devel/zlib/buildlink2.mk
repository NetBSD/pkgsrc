# $NetBSD: buildlink2.mk,v 1.4.2.1 2003/06/19 00:48:57 grant Exp $

.if !defined(ZLIB_BUILDLINK2_MK)
ZLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.zlib?=	zlib>=1.1.4nb1
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

# So does IRIX
_INCOMPAT_ZLIB+=	IRIX-*-*

# So does Darwin
_INCOMPAT_ZLIB+=	Darwin-*-*

# So does Linux
_INCOMPAT_ZLIB+=	Linux-*-*

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
_BLNK_ZLIB_LDFLAGS=		-L${BUILDLINK_PREFIX.zlib}/lib -lz
.else
BUILDLINK_PREFIX.zlib=		/usr
_BLNK_ZLIB_LDFLAGS=		-lz
.endif

LIBTOOL_ARCHIVE_UNTRANSFORM_SED+= \
	-e "s|${BUILDLINK_PREFIX.zlib}/lib/libz.la|${_BLNK_ZLIB_LDFLAGS}|g" \
	-e "s|${LOCALBASE}/lib/libz.la|${_BLNK_ZLIB_LDFLAGS}|g"

BUILDLINK_FILES.zlib=	include/zconf.h
BUILDLINK_FILES.zlib+=	include/zlib.h
BUILDLINK_FILES.zlib+=	lib/libz.*

BUILDLINK_TARGETS+=	zlib-buildlink
BUILDLINK_TARGETS+=	zlib-libz-la

zlib-buildlink: _BUILDLINK_USE

zlib-libz-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libz.la";				\
	libpattern="${BUILDLINK_PREFIX.zlib}/lib/libz.*";		\
	${BUILDLINK_FAKE_LA}

.endif	# ZLIB_BUILDLINK2_MK
