# $NetBSD: buildlink2.mk,v 1.3 2004/03/26 02:27:37 wiz Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		psycopg
BUILDLINK_DEPENDS.psycopg?=	${PYPKGPREFIX}-psycopg>=1.0.14nb1
BUILDLINK_RECOMMENDED.psycopg?=	${PYPKGPREFIX}-psycopg>=1.0.14nb2
BUILDLINK_PKGSRCDIR.psycopg?=	../../databases/py-psycopg
