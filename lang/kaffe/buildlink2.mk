# $NetBSD: buildlink2.mk,v 1.3 2004/04/25 11:40:38 wiz Exp $

.if !defined(KAFFE_BUILDLINK2_MK)
KAFFE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kaffe
BUILDLINK_PKGBASE.kaffe?=	kaffe
BUILDLINK_DEPENDS.kaffe?=	kaffe-[0-9]*
BUILDLINK_PKGSRCDIR.kaffe?=	../../lang/kaffe

BUILDLINK_PREFIX.kaffe=	${LOCALBASE}
BUILDLINK_FILES_CMD.kaffe= \
	${BUILDLINK_PLIST_CMD.kaffe} |					\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.kaffe=kaffe
BUILDLINK_JAVA_PREFIX.kaffe_DEFAULT= \
	${BUILDLINK_PREFIX.kaffe}/java/kaffe

BUILDLINK_CPPFLAGS.kaffe= \
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include			\
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include/kaffe

BUILDLINK_TARGETS+=	kaffe-buildlink

kaffe-buildlink: _BUILDLINK_USE

.endif	# KAFFE_BUILDLINK2_MK
