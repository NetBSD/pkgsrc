# $NetBSD: Makefile,v 1.8 2005/03/24 21:12:53 wiz Exp $

DISTNAME=	filelock-0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.ruby-lang.org/pub/ruby/contrib/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Ruby module which provides file locking mechanism

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF= 	yes
INSTALL_TARGET=		site-install
DOCS=			README
EXAMPLES=		test.rb	tst1.rb	tst2.rb	tst3.rb	tst4.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/filelock
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_EXAMPLESDIR}/filelock
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/filelock
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/filelock
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
