# $NetBSD: buildlink3.mk,v 1.1 2020/12/14 15:07:49 tnn Exp $

BUILDLINK_TREE+=	cpu_features

.if !defined(CPU_FEATURES_BUILDLINK3_MK)
CPU_FEATURES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cpu_features+=	cpu_features>=0.6.0
BUILDLINK_PKGSRCDIR.cpu_features?=	../../devel/cpu_features
BUILDLINK_DEPMETHOD.cpu_features?=	build

.endif	# CPU_FEATURES_BUILDLINK3_MK

BUILDLINK_TREE+=	-cpu_features
