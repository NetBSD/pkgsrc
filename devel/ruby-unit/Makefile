# $NetBSD: Makefile,v 1.9 2004/12/01 15:37:16 taca Exp $
# FreeBSD: ports/devel/ruby-runit/Makefile,v 1.10 2001/01/19 09:41:15 knu Exp

DISTNAME=	rubyunit-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-unit-${VERSION}
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage1.nifty.com/markey/ruby/rubyunit/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://homepage1.nifty.com/markey/ruby/rubyunit/index_e.html
COMMENT=	Ruby implementation of eXtreme Programming

VERSION=		0.5.6
USE_BUILDLINK3=		yes
USE_RUBY_INSTALL=	yes
RUBY_VERSION=		${RUBY16_VERSION}
REPLACE_RUBY=		bin/c2t.rb bin/runtest.rb

BINS=			c2t runtest
DOCS=			ChangeLog README README.ja ToDo
EXAMPLE=		sample01.rb sampletestsetup.rb simpletest.rb \
			testall.rb testarray.rb testrepeatedtest.rb \
			testtestsetup.rb

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${RUBY} makehtml.rb

post-install:
.for f in ${BINS}
	${MV} ${PREFIX}/bin/${f}.rb ${PREFIX}/bin/${f}
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

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
