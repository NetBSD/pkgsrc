# $NetBSD: Makefile,v 1.2 2001/07/11 16:25:41 taca Exp $
# FreeBSD: ports/devel/ruby-optparse/Makefile,v 1.10 2001/01/26 03:42:37 knu Exp

DISTNAME=	optparse-0.8.3
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://member.nifty.ne.jp/nokada/ruby.html
COMMENT=	Yet another command line option parser for Ruby

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	# empty

DOCS_EN=	ChangeLog README.en optparse.en.html
DOCS_JA=	FIRSTSTEP.ja.html README.ja optparse.ja.html
EXAMPLES=	cmd-ls.rb cmd.rb getopts.test.en opttest.rb \
		optparse/shellwords.rb optparse/time.rb optparse/uri.rb
EXAMPLES_JA=	getopts.test # rd/jfold.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/optparse.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/optparse/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/optparse
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/optparse/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/optparse/ja
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/optparse
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/optparse/ja
.endfor
	${INSTALL_MAN} ${WRKSRC}/optparse.1 ${LOCALBASE}/man/man1

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
