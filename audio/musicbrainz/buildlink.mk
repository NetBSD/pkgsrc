# $NetBSD: buildlink.mk,v 1.1.1.1 2002/04/19 20:23:58 zuntum Exp $
#
# This Makefile fragment is included by packages that use musicbrainz.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.musicbrainz to the dependency pattern
#     for the version of musicbrainz desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MUSICBRAINZ_BUILDLINK_MK)
MUSICBRAINZ_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.musicbrainz?=	musicbrainz>=1.1.0
DEPENDS+=	${BUILDLINK_DEPENDS.musicbrainz}:../../audio/musicbrainz

EVAL_PREFIX+=			BUILDLINK_PREFIX.musicbrainz=musicbrainz
BUILDLINK_PREFIX.musicbrainz_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.musicbrainz=	include/musicbrainz/bitprintinfo.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/errors.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/mb_c.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/musicbrainz.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/queries.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/bitzi/bitcollider.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/bitzi/gui_win32.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/bitzi/list.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/bitzi/plugin.h
BUILDLINK_FILES.musicbrainz+=	lib/libmusicbrainz.*

BUILDLINK_TARGETS.musicbrainz=	musicbrainz-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.musicbrainz}

pre-configure: ${BUILDLINK_TARGETS.musicbrainz}
musicbrainz-buildlink: _BUILDLINK_USE

.endif	# MUSICBRAINZ_BUILDLINK_MK
