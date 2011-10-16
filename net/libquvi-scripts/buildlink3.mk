# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/16 07:29:08 ryoon Exp $

BUILDLINK_TREE+=	libquvi-scripts

.if !defined(LIBQUVI_SCRIPTS_BUILDLINK3_MK)
LIBQUVI_SCRIPTS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libquvi-scripts?=	build
BUILDLINK_API_DEPENDS.libquvi-scripts+=	libquvi-scripts>=0.4.0
BUILDLINK_PKGSRCDIR.libquvi-scripts?=	../../net/libquvi-scripts
.endif	# LIBQUVI_SCRIPTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libquvi-scripts
