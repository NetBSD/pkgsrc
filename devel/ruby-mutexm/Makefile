# $NetBSD: Makefile,v 1.6 2004/11/28 07:52:46 taca Exp $
#

DISTNAME=	mutexm-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Extension module of Mutex mix-in

RUBY_VERSION=	${RUBY16_VERSION}
NO_BUILD=	# defined

DOCS=		mutexm.rd.ja

do-install:
	@cd ${WRKSRC}; ${RUBY} install.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mutexm
	${INSTALL_DATA} ${WRKSRC}/doc/mutexm.rd.ja ${RUBY_DOCDIR}/mutexm

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
