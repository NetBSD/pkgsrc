# $NetBSD: Makefile,v 1.16 2008/03/03 17:45:37 jlam Exp $

DISTNAME=	ruby-bsearch-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-bsearch-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://0xcc.net/ruby-bsearch/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://0xcc.net/ruby-bsearch/
COMMENT=	Binary search library for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	1.5
NO_CONFIGURE=	yes
TEST_DIRS=	${WRKSRC}/tests
TEST_TARGET=	check

RD_SRCS=	bsearch.en.rd bsearch.ja.rd
DOCS=		${RD_SRCS} bsearch.en.html bsearch.ja.html bsearch.png

do-build:
.for f in ${RD_SRCS}
	cd ${WRKSRC}; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/bsearch.rb ${DESTDIR}${RUBY_SITELIBDIR}/bsearch.rb
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/bsearch
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_DOCDIR}/bsearch
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
