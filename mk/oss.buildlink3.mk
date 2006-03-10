# $NetBSD: oss.buildlink3.mk,v 1.2 2006/03/10 07:31:32 wiz Exp $
#
# This Makefile fragment is included by packages that require an Open Sound
# System (OSS) implementation.
#
OSS_BUILDLINK3_MK:=	${OSS_BUILDLINK3_MK}+

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Noss}
BUILDLINK_PACKAGES+=		oss
BUILDLINK_BUILTIN_MK.oss=	../../mk/oss.builtin.mk

.if !empty(OSS_BUILDLINK3_MK:M+)
LIBOSSAUDIO?=		${BUILDLINK_LDADD.oss}
.include "bsd.prefs.mk"
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
