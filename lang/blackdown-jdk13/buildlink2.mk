# $NetBSD: buildlink2.mk,v 1.1 2002/10/13 07:51:34 jlam Exp $

.if !defined(BLACKDOWN_JDK13_BUILDLINK2_MK)
BLACKDOWN_JDK13_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			blackdown-jdk13
BUILDLINK_PKGBASE.blackdown-jdk13?=	blackdown-jdk13
BUILDLINK_DEPENDS.blackdown-jdk13?=	blackdown-jdk13-[0-9]*
BUILDLINK_PKGSRCDIR.blackdown-jdk13?=	../../lang/blackdown-jdk13

BUILDLINK_PREFIX.blackdown-jdk13=	${LOCALBASE}
BUILDLINK_FILES_CMD.blackdown-jdk13= \
	${BUILDLINK_PLIST_CMD.blackdown-jdk13} |			\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

BUILDLINK_CPPFLAGS.blackdown-jdk13= \
	-I${BUILDLINK_JAVA_PREFIX.blackdown-jre13}/include		\
	-I${BUILDLINK_JAVA_PREFIX.blackdown-jre13}/include/linux

.include "../../lang/blackdown-jre13/buildlink2.mk"

BUILDLINK_TARGETS+=	blackdown-jdk13-buildlink

blackdown-jdk13-buildlink: _BUILDLINK_USE

.endif	# BLACKDOWN_JDK13_BUILDLINK2_MK
