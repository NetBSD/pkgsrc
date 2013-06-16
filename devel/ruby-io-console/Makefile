# $NetBSD: Makefile,v 1.3 2013/06/16 15:10:41 taca Exp $

DISTNAME=	io-console-0.4.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nobu/io-console
COMMENT=	Add console capabilities to IO instances

GEM_CLEANBUILD=	Makefile console.${RUBY_DLEXT} *.o mkmf.log

RUBY_VERSION_SUPPORTED=	193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
