# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:47 jlam Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.10.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.pthread-stublib?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PTHREAD_STUBLIB_BUILDLINK3_MK:=	${PTHREAD_STUBLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pthread-stublib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npthread-stublib}
BUILDLINK_PACKAGES+=	pthread-stublib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pthread-stublib

.if !empty(PTHREAD_STUBLIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pthread-stublib+=	pthread-stublib>=1.0
BUILDLINK_PKGSRCDIR.pthread-stublib?=	../../devel/pthread-stublib
.endif	# PTHREAD_STUBLIB_BUILDLINK3_MK

IS_BUILTIN.pthread-stublib=no

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
