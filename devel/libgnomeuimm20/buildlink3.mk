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
# XXX	BUILDLINK_DEPMETHOD.libgnomeuimm20?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEUIMM20_BUILDLINK3_MK:=	${LIBGNOMEUIMM20_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeuimm20
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomeuimm20}
BUILDLINK_PACKAGES+=	libgnomeuimm20

.if !empty(LIBGNOMEUIMM20_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomeuimm20+=	libgnomeuimm20>=2.0.0
BUILDLINK_RECOMMENDED.libgnomeuimm20+=	libgnomeuimm20>=2.0.0nb1
BUILDLINK_PKGSRCDIR.libgnomeuimm20?=	../../devel/libgnomeuimm20
.endif	# LIBGNOMEUIMM20_BUILDLINK3_MK

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgnomemm20/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm20/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm20/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
