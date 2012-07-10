# $NetBSD: buildlink3.mk,v 1.2 2012/07/10 22:02:59 jmmv Exp $

BUILDLINK_TREE+=	atf-libs

.if !defined(ATF_LIBS_BUILDLINK3_MK)
ATF_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atf-libs+=	atf-libs>=0.16
BUILDLINK_PKGSRCDIR.atf-libs?=		../../devel/atf-libs
.endif	# ATF_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-atf-libs
