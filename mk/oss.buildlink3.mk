# $NetBSD: oss.buildlink3.mk,v 1.14 2020/04/11 10:31:14 nia Exp $
#
# This Makefile fragment is included by packages that require an Open Sound
# System (OSS) implementation.  After inclusion of this file, the following
# variables may be examined:
#
#    OSS_TYPE
#	The type of OSS implementation that has been found.  "native"
#	means the native OSS implementation is used.  "none" means that
#	no suitable OSS implementation could be found.
#
OSS_BUILDLINK3_MK:=	${OSS_BUILDLINK3_MK}+

.include "bsd.prefs.mk"

.if !defined(_OSS_TYPE)
_OSS_TYPE=		none
CHECK_BUILTIN.oss:=	yes
.  include "oss.builtin.mk"
CHECK_BUILTIN.oss:=	no
.  if defined(IS_BUILTIN.oss) && !empty(IS_BUILTIN.oss:M[yY][eE][sS])
_OSS_TYPE=		native
.  endif
.endif
MAKEVARS+=		_OSS_TYPE

OSS_TYPE=		${_OSS_TYPE}

.if ${OSS_TYPE} != "none"

BUILDLINK_TREE+=		oss -oss
BUILDLINK_BUILTIN_MK.oss=	../../mk/oss.builtin.mk

.if !empty(OSS_BUILDLINK3_MK:M+)
LIBOSSAUDIO?=		${BUILDLINK_LDADD.oss}
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
DEVOSSAUDIO?=		/dev/audio
DEVOSSSOUND?=		/dev/sound
DEVOSSMIDI?=		/dev/rmidi0
.  else
DEVOSSAUDIO?=		/dev/dsp
DEVOSSSOUND?=		/dev/dsp
DEVOSSMIDI?=		/dev/midi
.  endif

CONFIGURE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
CONFIGURE_ENV+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
CONFIGURE_ENV+=		DEVOSSSOUND=${DEVOSSSOUND:Q}

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
MAKE_ENV+=		DEVOSSSOUND=${DEVOSSSOUND:Q}
.endif	# OSS_BUILDLINK3_MK

.endif	# OSS_TYPE != none
