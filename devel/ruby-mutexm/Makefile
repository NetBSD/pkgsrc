# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 12:02:57 taca Exp $
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

DOCS_JA=	mutexm.rd.ja

do-install:
	@cd ${WRKSRC}; ${RUBY} install.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mutexm/ja
	${INSTALL_DATA} ${WRKSRC}/doc/mutexm.rd.ja ${RUBY_DOCDIR}/mutexm/ja
#	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mutexm

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
