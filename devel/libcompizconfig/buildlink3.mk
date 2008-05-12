# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/05/12 10:38:01 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCOMPIZCONFIG_BUILDLINK3_MK:=	${LIBCOMPIZCONFIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcompizconfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcompizconfig}
BUILDLINK_PACKAGES+=	libcompizconfig
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libcompizconfig

.if !empty(LIBCOMPIZCONFIG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libcompizconfig+=	libcompizconfig>=0.6.0
BUILDLINK_ABI_DEPENDS.libcompizconfig?=	libcompizconfig>=0.6.0
BUILDLINK_PKGSRCDIR.libcompizconfig?=	../../devel/libcompizconfig
.endif	# LIBCOMPIZCONFIG_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
