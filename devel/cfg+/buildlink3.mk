# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/08/27 13:05:58 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.5.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libcfg?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCFG_BUILDLINK3_MK:=	${LIBCFG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcfg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcfg}
BUILDLINK_PACKAGES+=	libcfg

.if !empty(LIBCFG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libcfg+=	libcfg+>=0.6.2
BUILDLINK_PKGSRCDIR.libcfg?=	../../devel/cfg+
.endif	# LIBCFG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
