# $NetBSD: Makefile,v 1.3 2002/01/04 09:47:56 taca Exp $

DISTNAME=	ruby-bsearch-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}bsearch-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://namazu.org/~satoru/ruby-bsearch/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://namazu.org/~satoru/ruby-bsearch/
COMMENT=	Binary search library for Ruby

VERSION=	1.4
DIST_SUBDIR=	ruby
USE_RUBY_RD=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined

RD_SRCS=	bsearch.en.rd bsearch.ja.rd
DOCS=		${RD_SRCS} bsearch.en.html bsearch.ja.html bsearch.png

do-build:
.for f in ${RD_SRCS}
	cd ${WRKSRC}; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/bsearch.rb ${RUBY_SITELIBDIR}/bsearch.rb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/bsearch
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/bsearch
.endfor

test:
	cd ${WRKSRC}/tests; make

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
