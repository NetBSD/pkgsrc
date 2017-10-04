# $NetBSD: Makefile,v 1.39 2017/10/04 13:13:59 wiz Exp $

DISTNAME=	scons-3.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

REPLACE_PYTHON+=	script/scons script/scons-configure-cache
REPLACE_PYTHON+=	script/scons-time script/sconsign

# scons-3.0.0 works with python-3.x, but not the many packages
# that have SConstruct files that only work with python-2.x
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
