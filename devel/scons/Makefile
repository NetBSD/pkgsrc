# $NetBSD: Makefile,v 1.32 2016/05/09 08:58:43 adam Exp $

DISTNAME=	scons-2.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

REPLACE_PYTHON+=	script/scons script/scons-time script/sconsign

# not yet ported as of 2.5.0, but progress promised
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
