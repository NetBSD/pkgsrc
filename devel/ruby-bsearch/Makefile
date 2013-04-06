# $NetBSD: Makefile,v 1.21 2013/04/06 15:46:36 rodent Exp $

DISTNAME=	ruby-bsearch-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-bsearch-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	http://0xcc.net/ruby-bsearch/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://0xcc.net/ruby-bsearch/
COMMENT=	Binary search library for Ruby
LICENSE=	ruby-license

VERSION=	1.5
NO_CONFIGURE=	yes
TEST_DIRS=	tests
TEST_TARGET=	check

RD_SRCS=	bsearch.en.rd bsearch.ja.rd
DOCS=		${RD_SRCS} bsearch.en.html bsearch.ja.html bsearch.png

INSTALLATION_DIRS=	${RUBY_DOC}/bsearch ${RUBY_VENDORLIB}

do-build:
.for f in ${RD_SRCS}
	cd ${WRKSRC}; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/bsearch.rb \
		${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}/bsearch.rb
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/bsearch
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
