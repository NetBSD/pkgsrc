# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:33 jlam Exp $

.include "../../lang/python/pyversion.mk"

.if !defined(PYPGSQL_BUILDLINK2_MK)
PYPGSQL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pyPgSQL
BUILDLINK_PKGBASE.pyPgSQL?=		${PYPKGPREFIX}-PgSQL
BUILDLINK_DEPENDS.pyPgSQL?=		${PYPKGPREFIX}-PgSQL>=2.4
BUILDLINK_RECOMMENDED.pyPgSQL?=		${PYPKGPREFIX}-PgSQL>=2.4nb1
BUILDLINK_PKGSRCDIR.pyPgSQL?=		../../databases/py-PgSQL

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyPgSQL=${PYPKGPREFIX}-PgSQL
BUILDLINK_PREFIX.pyPgSQL_DEFAULT=	${LOCALBASE}

.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	pyPgSQL-buildlink

pyPgSQL-buildlink: _BUILDLINK_USE

.endif	# PYPGSQL_BUILDLINK2_MK
