# $NetBSD: Makefile,v 1.3 2001/12/30 17:09:14 taca Exp $
# FreeBSD: ports/devel/ruby-optparse/Makefile,v 1.10 2001/01/26 03:42:37 knu Exp

DISTNAME=	optparse-0.8.6
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://member.nifty.ne.jp/nokada/ruby.html
COMMENT=	Yet another command line option parser for Ruby

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	# empty

DOCS=		ChangeLog FIRSTSTEP.ja.html README.en README.ja \
		optparse.html optparse.ja.html
EXAMPLES=	cmd-ls.rb cmd.rb getopts.test.en opttest.rb \
		optparse/shellwords.rb optparse/time.rb optparse/uri.rb \
		rd/jfold.rb
EXAMPLES_JA=	getopts.test

do-install:
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
	${INSTALL_MAN} ${WRKSRC}/optparse.1 ${LOCALBASE}/man/man1

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
