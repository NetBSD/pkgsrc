# $NetBSD: buildlink3.mk,v 1.4 2004/01/07 01:14:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OSS_BUILDLINK3_MK:=	${OSS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	oss
.endif

.if !empty(OSS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		oss
BUILDLINK_DEPENDS.oss?=		oss-[0-9]*
BUILDLINK_PKGSRCDIR.oss?=	../../audio/oss
BUILDLINK_INCDIRS.oss=		include lib/oss/include

# If we are using audio/oss, then we don't need the NetBSD OSS
# compatibility library.
#
BUILDLINK_TRANSFORM+=	l:ossaudio:

BUILDLINK_TARGETS+=	buildlink-oss-soundcard-h

LIBOSSAUDIO=	# empty
DEVOSSAUDIO=	/dev/dsp
DEVOSSSOUND=	${DEVOSSAUDIO}

# Many source files mistakenly include both <sys/soundcard.h> and
# <soundcard.h>, which causes errors since the definitions in the OSS
# sys/soundcard.h conflict with the definitions in the system soundcard.h.
# We fix this by making <sys/soundcard.h> and <soundcard.h> point to the
# same file and rely on multiple inclusion protection to prevent conflicts.
#
.PHONY: buildlink-oss-soundcard-h
buildlink-oss-soundcard-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	soundcard_h=${BUILDLINK_DIR}/include/soundcard.h;		\
	sys_soundcard_h=${BUILDLINK_PREFIX.oss}/lib/oss/include/sys/soundcard.h; \
	if [ ! -f $${soundcard_h} -a -f $${sys_soundcard_h} ]; then	\
		${ECHO_BUILDLINK_MSG}					\
			"Linking $${sys_soundcard_h} to $${soundcard_h}."; \
		${MKDIR} `${DIRNAME} $${soundcard_h}`;			\
		${LN} -s $${sys_soundcard_h} $${soundcard_h};		\
        fi
.endif	# OSS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
