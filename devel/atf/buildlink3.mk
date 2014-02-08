# $NetBSD: buildlink3.mk,v 1.3 2014/02/08 15:54:58 jmmv Exp $

BUILDLINK_TREE+=	atf

.if !defined(ATF_BUILDLINK3_MK)
ATF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atf+=		atf>=0.20
BUILDLINK_PKGSRCDIR.atf?=		../../devel/atf
.endif	# ATF_BUILDLINK3_MK

BUILDLINK_TREE+=	-atf
