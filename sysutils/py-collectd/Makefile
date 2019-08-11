# $NetBSD: Makefile,v 1.4 2019/08/11 13:23:16 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
COLLECTD_PACKAGE=	python

COMMENT=		Statistics collection daemon - python plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON_CONFIG=${PREFIX}/bin/python${PYVERSSUFFIX}-config

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
