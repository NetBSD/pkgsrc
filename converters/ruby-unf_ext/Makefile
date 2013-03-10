# $NetBSD: Makefile,v 1.3 2013/03/10 13:09:33 taca Exp $

DISTNAME=	unf_ext-0.0.6
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/knu/ruby-unf_ext
COMMENT=	Unicode Normalization Form support library for CRuby
LICENSE=	mit

USE_LANGUAGES=	c c++
GEM_CLEANBUILD=	Makefile *.o unf_ext.${RUBY_DLEXT} mkmf.log

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
