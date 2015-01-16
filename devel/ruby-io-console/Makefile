# $NetBSD: Makefile,v 1.7 2015/01/16 09:18:47 taca Exp $

DISTNAME=	io-console-0.4.2
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nobu/io-console
COMMENT=	Add console capabilities to IO instances

GEM_CLEANBUILD=	Makefile console.${RUBY_DLEXT} *.o mkmf.log \
	.RUBYARCHDIR.-.io.time .RUBYLIBDIR.-.io.-.console.time \
	.RUBYLIBDIR.-.console.time .RUBYARCHDIR.time
GEM_CLEANBUILD_EXTENSIONS= .RUBYARCHDIR.time .RUBYLIBDIR.-.console.time \
	io/console/size.rb

RUBY_VERSION_SUPPORTED=	21 200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
