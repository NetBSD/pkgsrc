# $NetBSD: buildlink2.mk,v 1.1 2002/10/13 07:51:36 jlam Exp $

.if !defined(JDK_BUILDLINK2_MK)
JDK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		jdk
BUILDLINK_PKGBASE.jdk?=		jdk
BUILDLINK_DEPENDS.jdk?=		jdk-[0-9]*
BUILDLINK_PKGSRCDIR.jdk?=	../../lang/jdk

BUILDLINK_PREFIX.jdk=	${LOCALBASE}
BUILDLINK_FILES_CMD.jdk= \
	${BUILDLINK_PLIST_CMD.jdk} |					\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.jdk=jdk
BUILDLINK_JAVA_PREFIX.jdk_DEFAULT= \
	${BUILDLINK_PREFIX.jdk}/java/jdk-1.1.8

BUILDLINK_CPPFLAGS.jdk= \
	-I${BUILDLINK_JAVA_PREFIX.jdk}/include				\
	-I${BUILDLINK_JAVA_PREFIX.jdk}/include/netbsd

BUILDLINK_TARGETS+=	jdk-buildlink

jdk-buildlink: _BUILDLINK_USE

.endif	# JDK_BUILDLINK2_MK
