# $NetBSD: Makefile,v 1.3 2018/08/22 09:46:40 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
COLLECTD_PACKAGE=	python

COMMENT=		Statistics collection daemon - python plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON_CONFIG=${PREFIX}/bin/python${PYVERSSUFFIX}-config

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
