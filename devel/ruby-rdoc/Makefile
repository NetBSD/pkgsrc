# $NetBSD: Makefile,v 1.5 2013/06/11 15:00:18 taca Exp $

DISTNAME=	rdoc-${RUBY_RDOC_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/rdoc
COMMENT=	Produces HTML and command-line documentation for Ruby projects
LICENSE=	gnu-gpl-v2 OR ruby-license

RUBY_JSON_REQD=	1.4
MAKE_ENV+=	RUBYLIB=${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}/lib
GEM_PATH=	${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}:${PREFIX}/${GEM_HOME}

pre-configure:
	${FIND} ${WRKSRC}/lib/rdoc/generator/template/darkfish/images \
		-type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/rdoc.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
