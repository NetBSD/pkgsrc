# $NetBSD: Makefile,v 1.2 2002/01/05 08:27:59 taca Exp $
#

DISTNAME=	mutexm-1.0.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Extention module of Mutex mix-in

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	yes

DOCS=		mutexm.rd.ja

do-install:
	@cd ${WRKSRC}; ${RUBY} install.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mutexm
	${INSTALL_DATA} ${WRKSRC}/doc/mutexm.rd.ja ${RUBY_DOCDIR}/mutexm

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
