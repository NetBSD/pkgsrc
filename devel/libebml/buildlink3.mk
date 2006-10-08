# $NetBSD: buildlink3.mk,v 1.14 2006/10/08 03:11:05 salo Exp $
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
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libebml

.if !empty(LIBEBML_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libebml+=	libebml>=0.7.7
BUILDLINK_ABI_DEPENDS.libebml?=	libebml>=0.7.7
BUILDLINK_PKGSRCDIR.libebml?=	../../devel/libebml
.endif	# LIBEBML_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
