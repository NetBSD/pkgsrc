# $NetBSD: Makefile,v 1.4 2002/01/19 16:33:17 taca Exp $
# FreeBSD: ports/devel/ruby-runit/Makefile,v 1.10 2001/01/19 09:41:15 knu Exp

DISTNAME=	rubyunit-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}unit-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://homepage1.nifty.com/markey/ruby/rubyunit/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://homepage1.nifty.com/markey/ruby/rubyunit/rubyunit_e.html
COMMENT=	Ruby implementation of eXtreme Programming

VERSION=	0.5.4
DIST_SUBDIR=	ruby
USE_RUBY_RD=	yes

REPLACE_RUBY=	bin/c2t.rb bin/runtest.rb

BINS=		c2t runtest
DOCS=		ChangeLog README README.ja ToDo
EXAMPLE=	sample01.rb sampletestsetup.rb simpletest.rb \
		testall.rb testarray.rb testrepeatedtest.rb testtestsetup.rb

do-build:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} makehtml.rb

do-install:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} install.rb
.for f in ${BINS}
	${LN} -sf ${f}.rb ${PREFIX}/bin/${f}
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/runit
.for f in ${EXAMPLE}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/runit
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/runit/ja
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/runit
.endfor
	${CP} -R ${WRKSRC}/doc_en/* ${RUBY_DOCDIR}/runit
	${CP} -R ${WRKSRC}/doc_ja/* ${RUBY_DOCDIR}/runit/ja

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
