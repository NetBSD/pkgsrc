# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:27 tv Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gconfmm26?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCONFMM26_BUILDLINK3_MK:=	${GCONFMM26_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gconfmm26
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngconfmm26}
BUILDLINK_PACKAGES+=	gconfmm26

.if !empty(GCONFMM26_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gconfmm26+=	gconfmm26>=2.6.1
BUILDLINK_RECOMMENDED.gconfmm26+=	gconfmm26>=2.6.1nb1
BUILDLINK_PKGSRCDIR.gconfmm26?=	../../devel/gconfmm26
.endif	# GCONFMM26_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/glibmm24/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
