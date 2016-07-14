# $NetBSD: buildlink3.mk,v 1.1 2016/07/14 20:01:06 bsiegert Exp $

BUILDLINK_TREE+=	gocheck

.if !defined(GOCHECK_BUILDLINK3_MK)
GOCHECK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.gocheck=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.gocheck?=		build

BUILDLINK_API_DEPENDS.gocheck+=	gocheck>=20160125
BUILDLINK_PKGSRCDIR.gocheck?=	../../devel/gocheck
.endif	# GOCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gocheck
