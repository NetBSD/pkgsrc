# $NetBSD: oss.buildlink3.mk,v 1.3 2006/03/10 22:33:24 jlam Exp $
#
# This Makefile fragment is included by packages that require an Open Sound
# System (OSS) implementation.
#
OSS_BUILDLINK3_MK:=	${OSS_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Noss}
BUILDLINK_PACKAGES+=		oss
BUILDLINK_BUILTIN_MK.oss=	../../mk/oss.builtin.mk

.if !empty(OSS_BUILDLINK3_MK:M+)
LIBOSSAUDIO?=		${BUILDLINK_LDADD.oss}
.  if (${OPSYS} == "Linux") && exists(/dev/dsp)
DEVOSSAUDIO?=		/dev/dsp
DEVOSSSOUND?=		/dev/dsp
.  else
DEVOSSAUDIO?=		/dev/audio
DEVOSSSOUND?=		/dev/sound
.  endif

CONFIGURE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
CONFIGURE_ENV+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
CONFIGURE_ENV+=		DEVOSSSOUND=${DEVOSSSOUND:Q}

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
MAKE_ENV+=		DEVOSSSOUND=${DEVOSSSOUND:Q}
.endif	# OSS_BUILDLINK3_MK
