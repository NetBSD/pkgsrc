# $NetBSD: buildlink.mk,v 1.3 2002/06/12 01:14:49 uebayasi Exp $
#
# This Makefile fragment is included by packages that use EB.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.eb to the dependency pattern
#     for the version of eb desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(EB_BUILDLINK_MK)
EB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

# <=3.2.1 packages didn't fix eb.conf.
BUILDLINK_DEPENDS.eb?=	eb>=3.2.2
DEPENDS+=	${BUILDLINK_DEPENDS.eb}:../../textproc/eb

EVAL_PREFIX+=		BUILDLINK_PREFIX.eb=eb
BUILDLINK_FILES.eb=	include/eb/*.h
BUILDLINK_FILES.eb+=	lib/libeb.*
BUILDLINK_FILES.eb+=	etc/eb.conf

# Fixing etc/eb.conf.
#	- Paths to headers/libraries are defined in eb.conf.  Fix them.
#	- Most packages use --with-eb-conf=... configure option to find
#	  eb.conf file.  Make sure if this is valid.
_CONFIGURE_PREREQ+=	eb-conf-buildlink-subst
BUILDLINK_SUBST_MESSAGE.eb-conf=	\
	"Fixing eb.conf file."
BUILDLINK_SUBST_FILES.eb-conf=	\
	${BUILDLINK_DIR}/etc/eb.conf
BUILDLINK_SUBST_SED.eb-conf=	\
	-e "s|-\([IL]\)${LOCALBASE}/|-\1${BUILDLINK_DIR}/|g"
eb-conf-buildlink-subst: _BUILDLINK_SUBST_USE
CONFIGURE_ARGS+=--with-eb-conf=${BUILDLINK_DIR}/etc/eb.conf

BUILDLINK_TARGETS.eb=	eb-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.eb}

.include "../../mk/bsd.prefs.mk"

pre-configure: ${BUILDLINK_TARGETS.eb}
eb-buildlink: _BUILDLINK_USE

.endif	# EB_BUILDLINK_MK
