# $NetBSD: Makefile,v 1.5 2014/03/14 17:55:49 taca Exp $

SHADOW_VER=	2.3.3
DISTNAME=	ruby-shadow-${SHADOW_VER}
PKGNAME=	${RUBY_PKGPREFIX}-shadow-${SHADOW_VER}
CATEGORIES=	databases security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apalmblad/ruby-shadow
COMMENT=	Access to shadow passwords on Linux and Solaris

USE_TOOLS+=		gmake

GEM_CLEANBUILD=	Makefile *.o mkmf.log shadow.${RUBY_DLEXT} .RUBYARCHDIR.time

CONFLICTS+=	ruby[1-9][0-9][0-9]-shadow-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
