# $NetBSD: buildlink2.mk,v 1.2 2003/05/02 11:54:15 wiz Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		psycopg
BUILDLINK_DEPENDS.psycopg?=	${PYPKGPREFIX}-psycopg>=1.0.14nb1
BUILDLINK_PKGSRCDIR.psycopg?=	../../databases/py-psycopg
