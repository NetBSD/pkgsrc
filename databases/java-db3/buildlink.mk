# $NetBSD: buildlink.mk,v 1.2 2001/08/25 16:56:41 wiz Exp $
#
# This Makefile fragment is included by packages that use java-db3.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.java-db3 to the dependency pattern
#     for the version of java-db3 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(JAVA_DB3_BUILDLINK_MK)
JAVA_DB3_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.java-db3?=	java-db3>=2.9
DEPENDS+=		${BUILDLINK_DEPENDS.java-db3}:../../databases/java-db3

EVAL_PREFIX+=			BUILDLINK_PREFIX.java-db3=java-db3
BUILDLINK_PREFIX.java-db3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.java-db3=	lib/db3.jar
BUILDLINK_FILES.java-db3+=	lib/libdb3_java.*

.include "../../databases/db3/buildlink.mk"

BUILDLINK_TARGETS.java-db3=	java-db3-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.java-db3}

pre-configure: ${BUILDLINK_TARGETS.java-db3}
java-db3-buildlink: _BUILDLINK_USE

.endif	# JAVA_DB3_BUILDLINK_MK
