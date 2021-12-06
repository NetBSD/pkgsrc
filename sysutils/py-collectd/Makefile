# $NetBSD: Makefile,v 1.6 2021/12/06 14:54:32 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
COLLECTD_PACKAGE=	python

COMMENT=		Statistics collection daemon - python plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON_CONFIG=${PREFIX}/bin/python${PYVERSSUFFIX}-config

# installed by collectd package
post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/libcollectdclient.*

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
