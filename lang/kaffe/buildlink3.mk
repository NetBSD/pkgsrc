# $NetBSD: buildlink3.mk,v 1.1 2004/04/06 16:59:37 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KAFFE_BUILDLINK3_MK:=	${KAFFE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kaffe
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkaffe}
BUILDLINK_PACKAGES+=	kaffe

.if !empty(KAFFE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kaffe+=	kaffe-[0-9]*
BUILDLINK_PKGSRCDIR.kaffe?=	../../lang/kaffe
.endif	# KAFFE_BUILDLINK3_MK

BUILDLINK_FILES_CMD.kaffe=				    \
	${BUILDLINK_PLIST_CMD.kaffe} |			    \
	    ${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |    \
	    ${SED} "s,^,$${pkg_prefix},"

BUILDLINK_JAVA_PREFIX.kaffe=	${BUILDLINK_PREFIX.kaffe}/java/kaffe

BUILDLINK_CPPFLAGS.kaffe=				    \
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include	    \
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include/kaffe

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
