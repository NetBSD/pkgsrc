# $NetBSD: buildlink3.mk,v 1.1 2005/07/29 15:51:40 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_LDAP_BUILDLINK3_MK:=	${PY_LDAP_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyldap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyldap}
BUILDLINK_PACKAGES+=	pyldap

.if !empty(PY_LDAP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyldap+=	${PYPKGPREFIX}-ldap-*
BUILDLINK_PKGSRCDIR.pyldap?=	../../databases/py-ldap
.endif	# PY_LDAP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
