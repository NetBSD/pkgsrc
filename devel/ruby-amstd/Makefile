# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 23:29:39 taca Exp $
# FreeBSD: ports/devel/ruby-amstd/Makefile,v 1.8 2000/12/06 15:38:58 knu Exp

DISTNAME=	amstd-1.9.7
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www9.xdsl.ne.jp/~aamine/soft/ \
		http://www1.u-netsurf.ne.jp/~brew/mine/soft/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www1.u-netsurf.ne.jp/~brew/mine/
COMMENT=	Collection of miscellaneous Ruby modules

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	# defined

DOCS_EN=	README.en
DOCS_JA=	README.ja amstd-ja.rd
SRCS=		bench.rb bug.rb collfrom.rb constdef.rb dispatch.rb \
		errutil.rb extmod.rb fileutils.rb futils.rb gconst.rb \
		getdep.rb info.rb must.rb pipeline.rb rbparams.rb recycle.rb \
		rubyemu.rb strquote.rb symbol.rb timer.rb to_s.rb version.rb

do-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/amstd
.for f in ${SRCS}
	${INSTALL_DATA} ${WRKSRC}/lib/amstd/${f} ${RUBY_SITELIBDIR}/amstd
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/amstd/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/amstd
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/amstd/ja
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
