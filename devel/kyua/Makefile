# $NetBSD: Makefile,v 1.37 2026/01/07 08:46:39 wiz Exp $

DISTNAME=	kyua-0.14.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=freebsd/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freebsd/kyua/
COMMENT=	Testing framework for infrastructure software
LICENSE=	modified-bsd

CONFLICTS=	kyua-atf-compat-[0-9]* kyua-cli-[0-9]* kyua-testers-[0-9]*

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS=		gmake pkg-config

CONFIGURE_ARGS+=	KYUA_CONFSUBDIR=
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-doxygen

PKG_SYSCONFSUBDIR=	kyua

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/lutok/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
