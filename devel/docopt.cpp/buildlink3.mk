# $NetBSD: buildlink3.mk,v 1.1 2025/08/31 19:15:04 wiz Exp $

BUILDLINK_TREE+=	docopt.cpp

.if !defined(DOCOPT.CPP_BUILDLINK3_MK)
DOCOPT.CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.docopt.cpp+=	docopt.cpp>=0.6.3
BUILDLINK_PKGSRCDIR.docopt.cpp?=	../../devel/docopt.cpp
.endif	# DOCOPT.CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-docopt.cpp
