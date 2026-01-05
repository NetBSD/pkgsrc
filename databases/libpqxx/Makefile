# $NetBSD: Makefile,v 1.44 2026/01/05 09:19:25 wiz Exp $

DISTNAME=		libpqxx-7.8.1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=jtv/}
GITHUB_PROJECT=		libpqxx

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		https://pqxx.org/development/libpqxx/
COMMENT=		C++ interface to postgresql-lib
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libpqxx.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON+=	tools/m4esc.py
REPLACE_PYTHON+=	tools/splitconfig

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
