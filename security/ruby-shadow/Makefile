# $NetBSD: Makefile,v 1.1.1.1.2.1 2013/07/16 17:00:51 tron Exp $

SHADOW_VER=	2.2.0
DISTNAME=	ruby-shadow-${SHADOW_VER}
PKGNAME=	${RUBY_PKGPREFIX}-shadow-${SHADOW_VER}
PKGREVISION=	1
CATEGORIES=	database

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apalmblad/ruby-shadow
COMMENT=	Access to shadow passwords on Linux and Solaris

USE_TOOLS+=		gmake

GEM_CLEANBUILD=	Makefile *.o mkmf.log shadow.${RUBY_DLEXT}

CONFLICTS+=	ruby[1-9][0-9][0-9]-shadow-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
