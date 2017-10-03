# $NetBSD: Makefile,v 1.36 2017/10/03 11:53:52 wiz Exp $

DISTNAME=	scons-3.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

REPLACE_PYTHON+=	script/scons script/scons-configure-cache
REPLACE_PYTHON+=	script/scons-time script/sconsign

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
