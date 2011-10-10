# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/10 13:15:31 adam Exp $

BUILDLINK_TREE+=	tclap

.if !defined(TCLAP_BUILDLINK3_MK)
TCLAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tclap+=	tclap>=1.2.1
BUILDLINK_PKGSRCDIR.tclap?=	../../devel/tclap
.endif	# TCLAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-tclap
