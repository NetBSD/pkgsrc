# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:30 tv Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libgnomeuimm26?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEUIMM26_BUILDLINK3_MK:=	${LIBGNOMEUIMM26_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeuimm26
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomeuimm26}
BUILDLINK_PACKAGES+=	libgnomeuimm26

.if !empty(LIBGNOMEUIMM26_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomeuimm26+=	libgnomeuimm26>=2.6.0
BUILDLINK_RECOMMENDED.libgnomeuimm26+=	libgnomeuimm26>=2.6.0nb1
BUILDLINK_PKGSRCDIR.libgnomeuimm26?=	../../devel/libgnomeuimm26
.endif	# LIBGNOMEUIMM26_BUILDLINK3_MK

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgnomemm26/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm26/buildlink3.mk"
.include "../../devel/gconfmm26/buildlink3.mk"
.include "../../devel/libglademm24/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm26/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
