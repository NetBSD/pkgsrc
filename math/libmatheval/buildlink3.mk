# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:12:56 tv Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libmatheval?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMATHEVAL_BUILDLINK3_MK:=	${LIBMATHEVAL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmatheval
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmatheval}
BUILDLINK_PACKAGES+=	libmatheval

.if !empty(LIBMATHEVAL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmatheval+=	libmatheval>=1.1.0
BUILDLINK_RECOMMENDED.libmatheval+=	libmatheval>=1.1.1nb1
BUILDLINK_PKGSRCDIR.libmatheval?=	../../math/libmatheval
.endif	# LIBMATHEVAL_BUILDLINK3_MK

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
