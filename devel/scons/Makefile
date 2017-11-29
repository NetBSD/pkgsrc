# $NetBSD: Makefile,v 1.40 2017/11/29 09:07:58 adam Exp $

DISTNAME=	scons-3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scons/}
MASTER_SITES+=	${MASTER_SITE_PYPI:=S/Scons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

REPLACE_PYTHON+=	script/scons
REPLACE_PYTHON+=	script/scons-configure-cache
REPLACE_PYTHON+=	script/scons-time
REPLACE_PYTHON+=	script/sconsign

# scons-3.0.0 works with python-3.x, but not the many packages
# that have SConstruct files that only work with python-2.x
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
