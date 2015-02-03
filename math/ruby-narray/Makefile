# $NetBSD: Makefile,v 1.5 2015/02/03 14:46:01 taca Exp $

DISTNAME=	narray-0.6.1.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://narray.rubyforge.org/
COMMENT=	N-dimensional Numerical Array class for Ruby
LICENSE=	2-clause-bsd OR ruby-license

GEM_CLEANBUILD=	src/Makefile src/*.o src/.RUBY*.time src/*.${RUBY_DLEXT} \
		src/mkmf.log
GEM_CLEANBUILD_EXTENSIONS= narray.h narray_config.h narray_ext.rb nmatrix.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
