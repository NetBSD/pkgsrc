# $NetBSD: buildlink3.mk,v 1.1 2019/04/08 16:15:41 adam Exp $

BUILDLINK_TREE+=	go-ldap

.if !defined(GO_LDAP_BUILDLINK3_MK)
GO_LDAP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ldap=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ldap?=		build

BUILDLINK_API_DEPENDS.go-ldap+=		go-ldap>=3.0.2
BUILDLINK_PKGSRCDIR.go-ldap?=		../../databases/go-ldap

.endif	# GO_LDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ldap
