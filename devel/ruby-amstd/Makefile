# $NetBSD: Makefile,v 1.2 2001/12/30 17:01:49 taca Exp $
# FreeBSD: ports/devel/ruby-amstd/Makefile,v 1.8 2000/12/06 15:38:58 knu Exp

DISTNAME=	amstd-1.10.0
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.loveruby.net/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.loveruby.net/en/amstd.html
COMMENT=	Collection of miscellaneous Ruby modules

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	# defined

DOCS=		README.en README.ja amstd-ja.rd
SRCS=		aliascm.rb bench.rb bug.rb collfrom.rb constdef.rb d.rb \
		daemon.rb dispatch.rb extmod.rb fileutils.rb futils.rb \
		gconst.rb getdep.rb info.rb must.rb protect.rb rbparams.rb \
		recycle.rb rubyemu.rb strquote.rb symbol.rb timer.rb to_s.rb \
		version.rb

do-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/amstd
.for f in ${SRCS}
	${INSTALL_DATA} ${WRKSRC}/lib/amstd/${f} ${RUBY_SITELIBDIR}/amstd
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/amstd
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/amstd
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
