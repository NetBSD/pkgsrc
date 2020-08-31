# $NetBSD: Makefile,v 1.5 2020/08/31 18:11:34 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
COLLECTD_PACKAGE=	python

COMMENT=		Statistics collection daemon - python plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON_CONFIG=${PREFIX}/bin/python${PYVERSSUFFIX}-config

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
