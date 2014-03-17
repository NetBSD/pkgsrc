# $NetBSD: Makefile,v 1.3 2014/03/17 14:17:22 taca Exp $

DISTNAME=	narray-0.6.0.8
PKGREVISION=	1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://narray.rubyforge.org/
COMMENT=	N-dimensional Numerical Array class for Ruby
LICENSE=	2-clause-bsd OR ruby-license

GEM_CLEANBUILD=	src/Makefile src/*.o src/.RUBY*.time src/*.${RUBY_DLEXT} \
		src/mkmf.log
GEM_CLEANBUOLD_EXTENSIONS= narray.h narray_config.h narray_ext.rb nmatrix.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
