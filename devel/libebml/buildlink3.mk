# $NetBSD: buildlink3.mk,v 1.4 2004/10/14 16:59:36 salo Exp $
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

.if !empty(LIBEBML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libebml+=	libebml>=0.7.2
BUILDLINK_PKGSRCDIR.libebml?=	../../devel/libebml
.endif	# LIBEBML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
