# $NetBSD: Makefile,v 1.35 2017/01/01 14:43:37 wiz Exp $

DISTNAME=	scons-2.5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

REPLACE_PYTHON+=	script/scons script/scons-configure-cache
REPLACE_PYTHON+=	script/scons-time script/sconsign

# not yet ported as of 2.5.1, but progress promised
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
