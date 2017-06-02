# $NetBSD: Makefile,v 1.8 2017/06/02 04:16:35 taca Exp $

DISTNAME=	narray-0.6.1.2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://masa16.github.io/narray/
COMMENT=	N-dimensional Numerical Array class for Ruby
LICENSE=	2-clause-bsd OR ruby-license

GEM_CLEANBUILD=	src/Makefile src/*.o src/.*.time src/*.${RUBY_DLEXT} \
		src/mkmf.log
GEM_CLEANBUILD_EXTENSIONS= narray.h narray_config.h narray_ext.rb nmatrix.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
