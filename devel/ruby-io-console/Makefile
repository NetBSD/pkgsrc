# $NetBSD: Makefile,v 1.4 2013/07/21 02:39:27 taca Exp $

DISTNAME=	io-console-0.4.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nobu/io-console
COMMENT=	Add console capabilities to IO instances

GEM_CLEANBUILD=	Makefile console.${RUBY_DLEXT} *.o mkmf.log .RUBYARCHDIR.time

RUBY_VERSION_SUPPORTED=	200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
