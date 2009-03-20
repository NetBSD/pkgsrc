# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:12 joerg Exp $

BUILDLINK_TREE+=	solaris-tap

.if !defined(SOLARIS_TAP_BUILDLINK3_MK)
SOLARIS_TAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.solaris-tap+=	solaris-tap>=20070525
BUILDLINK_PKGSRCDIR.solaris-tap?=	../../net/solaris-tap
BUILDLINK_DEPMETHOD.solaris-tap?=	build
.endif # SOLARIS_TAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-solaris-tap
