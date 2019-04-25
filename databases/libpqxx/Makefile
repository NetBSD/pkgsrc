# $NetBSD: Makefile,v 1.35 2019/04/25 07:32:40 maya Exp $

DISTNAME=		libpqxx-6.2.2
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=jtv/}
GITHUB_PROJECT=		libpqxx

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://pqxx.org/development/libpqxx/
COMMENT=		C++ interface to postgresql-lib
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libpqxx.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON+=	tools/splitconfig
REPLACE_PYTHON+=	tools/template2mak.py

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
