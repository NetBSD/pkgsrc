# $NetBSD: buildlink2.mk,v 1.4 2004/03/29 05:05:33 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		psycopg
BUILDLINK_PKGBASE.psycopg?=	${PYPKGPREFIX}-psycopg
BUILDLINK_DEPENDS.psycopg?=	${PYPKGPREFIX}-psycopg>=1.0.14nb1
BUILDLINK_RECOMMENDED.psycopg?=	${PYPKGPREFIX}-psycopg>=1.0.14nb2
BUILDLINK_PKGSRCDIR.psycopg?=	../../databases/py-psycopg
