# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 12:40:19 taca Exp $
# FreeBSD: ports/devel/ruby-filelock/Makefile,v 1.4 2000/09/26 08:01:52 knu Exp

DISTNAME=	filelock-0.2
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/contrib/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	# not available
COMMENT=	Ruby module which provides file locking mechanism

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

INSTALL_TARGET=	site-install

DOCS=		README
EXAMPLES=	test.rb	tst1.rb	tst2.rb	tst3.rb	tst4.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/filelock
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_EXAMPLESDIR}/filelock
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/filelock
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/filelock
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
