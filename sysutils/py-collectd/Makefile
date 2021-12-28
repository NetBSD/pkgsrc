# $NetBSD: Makefile,v 1.7 2021/12/28 01:11:53 nros Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		4
COLLECTD_PACKAGE=	python

COMMENT=		Statistics collection daemon - python plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON_CONFIG=${PREFIX}/bin/python${PYVERSSUFFIX}-config

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
