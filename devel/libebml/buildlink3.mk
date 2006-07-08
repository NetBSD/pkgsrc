# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 22:39:10 jlam Exp $
#
# This Makefile fragment is included by packages that use libebml.
#

BUILDLINK_DEPMETHOD.libebml?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBEBML_BUILDLINK3_MK:=	${LIBEBML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libebml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibebml}
BUILDLINK_PACKAGES+=	libebml
BUILDLINK_ORDER+=	libebml

.if !empty(LIBEBML_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libebml+=	libebml>=0.7.6
BUILDLINK_ABI_DEPENDS.libebml?=	libebml>=0.7.6nb1
BUILDLINK_PKGSRCDIR.libebml?=	../../devel/libebml
.endif	# LIBEBML_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
