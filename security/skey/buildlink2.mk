# $NetBSD: buildlink2.mk,v 1.1 2002/08/28 03:03:22 jlam Exp $

.if !defined(SKEY_BUILDLINK2_MK)
SKEY_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.skey?=	skey>=1.1.5
BUILDLINK_PKGSRCDIR.skey?=	../../security/skey

# security/skey only installs static libraries
BUILDLINK_DEPMETHOD.skey?=	build

.if defined(USE_SKEY)
_NEED_SKEY=		YES
.else
.  if exists(/usr/include/skey.h)
_NEED_SKEY=		NO
.  else
_NEED_SKEY=		YES
.  endif

INCOMPAT_SKEY?=		# empty
.  for _pattern_ in ${_INCOMPAT_SKEY} ${INCOMPAT_SKEY}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_SKEY=		YES
.    endif
.  endfor
.endif

.if ${_NEED_SKEY} == "YES"
BUILDLINK_PACKAGES+=		skey
EVAL_PREFIX+=			BUILDLINK_PREFIX.skey=skey
BUILDLINK_PREFIX.skey_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.skey=		/usr
.endif

BUILDLINK_FILES.skey=	include/rmd160.h
BUILDLINK_FILES.skey+=	include/sha1.h
BUILDLINK_FILES.skey+=	include/skey.h
BUILDLINK_FILES.skey+=	lib/libskey.*

BUILDLINK_TARGETS+=	skey-buildlink

skey-buildlink: _BUILDLINK_USE

.endif	# SKEY_BUILDLINK2_MK
