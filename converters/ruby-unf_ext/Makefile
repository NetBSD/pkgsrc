# $NetBSD: Makefile,v 1.2 2012/06/01 12:02:24 taca Exp $

DISTNAME=	unf_ext-0.0.5
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/knu/ruby-unf_ext
COMMENT=	Unicode Normalization Form support library for CRuby
LICENSE=	mit

USE_LANGUAGES=	c c++
GEM_CLEANBUILD=	Makefile *.o unf_ext.${RUBY_DLEXT} mkmf.log

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
