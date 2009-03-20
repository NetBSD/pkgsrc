# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:07 joerg Exp $

BUILDLINK_TREE+=	pyldap

.if !defined(PY_LDAP_BUILDLINK3_MK)
PY_LDAP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyldap+=	${PYPKGPREFIX}-ldap>=2.2.0
BUILDLINK_ABI_DEPENDS.pyldap+=	${PYPKGPREFIX}-ldap>=2.2.0
BUILDLINK_PKGSRCDIR.pyldap?=	../../databases/py-ldap
.endif # PY_LDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyldap
