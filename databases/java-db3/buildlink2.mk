# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:08 jlam Exp $

.if !defined(JAVA_DB3_BUILDLINK2_MK)
JAVA_DB3_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		java-db3
BUILDLINK_DEPENDS.java-db3?=	java-db3>=2.9
BUILDLINK_PKGSRCDIR.java-db3?=	../../databases/java-db3

EVAL_PREFIX+=			BUILDLINK_PREFIX.java-db3=java-db3
BUILDLINK_PREFIX.java-db3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.java-db3=	lib/db3.jar
BUILDLINK_FILES.java-db3+=	lib/libdb3_java.*

.include "../../databases/db3/buildlink2.mk"

BUILDLINK_TARGETS+=	java-db3-buildlink

java-db3-buildlink: _BUILDLINK_USE

.endif	# JAVA_DB3_BUILDLINK2_MK
