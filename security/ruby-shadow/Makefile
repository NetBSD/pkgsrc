# $NetBSD: Makefile,v 1.1.1.1 2013/04/10 09:25:21 tonnerre Exp $

SHADOW_VER=	2.2.0
DISTNAME=	ruby-shadow-${SHADOW_VER}
PKGNAME=	${RUBY_PKGPREFIX}-shadow-${SHADOW_VER}
CATEGORIES=	database

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apalmblad/ruby-shadow
COMMENT=	Access to shadow passwords on Linux and Solaris

USE_RUBY_EXTCONF=	yes
USE_TOOLS+=		gmake

CONFLICTS+=	ruby[1-9][0-9][0-9]-shadow-[0-9]*

.include "../../lang/ruby/gem.mk"

.include "../../devel/libuuid/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
