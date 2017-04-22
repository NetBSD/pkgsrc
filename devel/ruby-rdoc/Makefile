# $NetBSD: Makefile,v 1.16 2017/04/22 18:27:04 taca Exp $

DISTNAME=	rdoc-${RUBY_RDOC_PKGSRC_VERS}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/rdoc
COMMENT=	Produces HTML and command-line documentation for Ruby projects
LICENSE=	gnu-gpl-v2 OR ruby-license

# ruby23 has 4.2.1 in tree.
RUBY_VERSIONS_ACCEPTED= 22 21

RUBY_JSON_REQD=	1.4
GEM_PATH=	${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}:${PREFIX}/${GEM_HOME}

pre-configure:
	${FIND} ${WRKSRC}/lib/rdoc/generator/template/darkfish/images \
		-type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/rdoc.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
