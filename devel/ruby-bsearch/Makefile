# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 11:58:20 taca Exp $

DISTNAME=	ruby-bsearch-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}bsearch-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://namazu.org/~satoru/ruby-bsearch/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://namazu.org/~satoru/ruby-bsearch/
COMMENT=	Binary search library for Ruby

VERSION=	1.1
DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_PATCH=	# defined
NO_CONFIGURE=	# defined

do-build:
	cd ${WRKSRC}/tests; make

do-install:
	${INSTALL_DATA} ${WRKSRC}/bsearch.rb ${RUBY_SITELIBDIR}/bsearch.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
