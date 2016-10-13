# $NetBSD: Makefile,v 1.2 2016/10/13 15:17:29 fhajny Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
COLLECTD_PACKAGE=	python

COMMENT=		Statistics collection daemon - python plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON_CONFIG=${PREFIX}/bin/python${PYVERSSUFFIX}-config

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
