# $NetBSD: buildlink.mk,v 1.3.2.2 2002/06/23 18:43:45 jlam Exp $
#
# This Makefile fragment is included by packages that use gconf2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gconf2 to the dependency pattern
#     for the version of gconf2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GCONF2_BUILDLINK_MK)
GCONF2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gconf2?=	GConf2>=1.1.10
DEPENDS+=	${BUILDLINK_DEPENDS.gconf2}:../../devel/GConf2

EVAL_PREFIX+=				BUILDLINK_PREFIX.gconf2=GConf2
BUILDLINK_PREFIX.gconf2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gconf2=			include/gconf/2/gconf/*
BUILDLINK_FILES.gconf2+=		lib/libgconf-2*

REPLACE_BUILDLINK_SED+=	\
	-e "s|-I${BUILDLINK_DIR}/\(include/gconf/\)|-I${BUILDLINK_PREFIX.gconf2}/\1|g"

.include "../../databases/db3/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"

BUILDLINK_TARGETS.gconf2=	gconf2-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gconf2}

pre-configure: ${BUILDLINK_TARGETS.gconf2}
gconf2-buildlink: _BUILDLINK_USE

.endif	# GCONF2_BUILDLINK_MK
