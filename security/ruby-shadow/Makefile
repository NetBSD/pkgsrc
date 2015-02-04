# $NetBSD: Makefile,v 1.6 2015/02/04 16:14:57 taca Exp $

SHADOW_VER=	2.4.1
DISTNAME=	ruby-shadow-${SHADOW_VER}
PKGNAME=	${RUBY_PKGPREFIX}-shadow-${SHADOW_VER}
CATEGORIES=	databases security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apalmblad/ruby-shadow
COMMENT=	Access to shadow passwords on Linux and Solaris

USE_TOOLS+=		gmake

GEM_CLEANBUILD=	Makefile *.o mkmf.log shadow.${RUBY_DLEXT} .RUBYARCHDIR.time

.include "../../lang/ruby/gem.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
