# $NetBSD: buildlink3.mk,v 1.4 2004/11/02 00:05:23 adrianp Exp $
# XXX	BUILDLINK_DEPMETHOD.libnasl?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBNASL_BUILDLINK3_MK:=	${LIBNASL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libnasl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibnasl}
BUILDLINK_PACKAGES+=	libnasl

.if !empty(LIBNASL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libnasl+=	libnasl>=2.2.0
BUILDLINK_RECOMMENDED.libnasl?=	libnasl>=2.2.0
BUILDLINK_PKGSRCDIR.libnasl?=	../../security/libnasl
.endif	# LIBNASL_BUILDLINK3_MK

.include "../../security/nessus-libraries/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
