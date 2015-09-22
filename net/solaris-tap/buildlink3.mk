# $NetBSD: buildlink3.mk,v 1.3 2015/09/22 02:38:32 tnn Exp $

BUILDLINK_TREE+=	solaris-tap

.if !defined(SOLARIS_TAP_BUILDLINK3_MK)
SOLARIS_TAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.solaris-tap+=	solaris-tap>=1.1.0
BUILDLINK_PKGSRCDIR.solaris-tap?=	../../net/solaris-tap
BUILDLINK_DEPMETHOD.solaris-tap?=	build
.endif # SOLARIS_TAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-solaris-tap
