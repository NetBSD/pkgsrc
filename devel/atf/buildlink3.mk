# $NetBSD: buildlink3.mk,v 1.1 2011/06/14 13:55:15 jmmv Exp $

BUILDLINK_TREE+=	atf

.if !defined(ATF_BUILDLINK3_MK)
ATF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atf+=	atf>=0.14
# The atf-c and atf-c++ libraries are installed in their static form only,
# which means that we could have a build-time dependency only on atf...
# Unfortunately, test programs using atf-sh still need a full dependency.
#BUILDLINK_DEPMETHOD.atf?=	build
BUILDLINK_PKGSRCDIR.atf?=	../../devel/atf
.endif	# ATF_BUILDLINK3_MK

BUILDLINK_TREE+=	-atf
