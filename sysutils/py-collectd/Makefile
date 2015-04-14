# $NetBSD: Makefile,v 1.1 2015/04/14 11:27:30 fhajny Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
COLLECTD_PACKAGE=	python

COMMENT=		Statistics collection daemon - python plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
