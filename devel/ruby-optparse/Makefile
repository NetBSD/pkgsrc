# $NetBSD: Makefile,v 1.13 2005/06/17 04:49:46 jlam Exp $

DISTNAME=	optparse-0.12
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://nokada.jin.gr.jp/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Yet another command line option parser for Ruby

RUBY_VERSION=	${RUBY16_VERSION}
NO_BUILD=	yes

DOCS=		ChangeLog FIRSTSTEP.ja.html README.en README.ja \
		optparse.html optparse.ja.html
EXAMPLES=	cmd-ls.rb cmd.rb getopts.test.en opttest.rb \
		optparse/shellwords.rb optparse/time.rb optparse/uri.rb \
		rd/jfold.rb
EXAMPLES_JA=	getopts.test

INSTALLATION_DIRS=	man/man3

do-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/optparse.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/optparse
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/optparse
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/optparse
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/optparse
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/optparse/${f}.ja
.endfor
	${INSTALL_MAN} ${WRKSRC}/optparse.1 ${PREFIX}/man/man3/optparse.3

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
