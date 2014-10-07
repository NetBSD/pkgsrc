# $NetBSD: Makefile,v 1.27 2014/10/07 10:17:28 adam Exp $

DISTNAME=	scons-2.3.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

REPLACE_PYTHON+=	script/scons script/scons-time script/sconsign

# not yet ported as of 2.3.0, but progress promised
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
