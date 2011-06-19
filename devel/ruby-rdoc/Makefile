# $NetBSD: Makefile,v 1.2 2011/06/19 00:48:24 taca Exp $

DISTNAME=	rdoc-${RUBY_RDOC_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/rdoc
COMMENT=	produces HTML and command-line documentation for Ruby projects
LICENSE=	gnu-gpl-v2 OR ruby-license

MAKE_ENV+=	RUBYLIB=${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}/lib

.include "../../lang/ruby/rdoc.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
