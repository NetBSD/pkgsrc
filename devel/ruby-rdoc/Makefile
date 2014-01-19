# $NetBSD: Makefile,v 1.8 2014/01/19 12:57:42 taca Exp $

DISTNAME=	rdoc-4.0.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/rdoc
COMMENT=	Produces HTML and command-line documentation for Ruby projects
LICENSE=	gnu-gpl-v2 OR ruby-license

RUBY_JSON_REQD=	1.4
GEM_PATH=	${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}:${PREFIX}/${GEM_HOME}

pre-configure:
	${FIND} ${WRKSRC}/lib/rdoc/generator/template/darkfish/images \
		-type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/rdoc.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
