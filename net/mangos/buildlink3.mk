# $NetBSD: buildlink3.mk,v 1.1 2022/04/20 10:10:59 khorben Exp $

BUILDLINK_TREE+=	mangos

.if !defined(MANGOS_BUILDLINK3_MK)
MANGOS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.mangos=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.mangos?=		build

BUILDLINK_API_DEPENDS.mangos+=		mangos>=3.4.1
BUILDLINK_PKGSRCDIR.mangos?=		../../net/mangos

.endif	# MANGOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mangos
