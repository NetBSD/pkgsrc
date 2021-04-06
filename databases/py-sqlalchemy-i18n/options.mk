# $NetBSD: options.mk,v 1.3 2021/04/06 14:23:25 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-sqlalchemy-i18n
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
PYTHON_VERSIONED_DEPENDENCIES=	pygments test
.include "../../lang/python/versioned_dependencies.mk"
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.4.6:../../databases/py-psycopg2
.endif
