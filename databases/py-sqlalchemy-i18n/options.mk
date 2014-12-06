# $NetBSD: options.mk,v 1.1 2014/12/06 03:26:17 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-sqlalchemy-i18n
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=	${PYPKGPREFIX}-test>=2.2.3:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.4.6:../../databases/py-psycopg2
.endif
