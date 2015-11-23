# $NetBSD: Makefile,v 1.7 2015/11/23 07:26:14 taca Exp $

SHADOW_VER=	2.5.0
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
