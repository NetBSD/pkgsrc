# $NetBSD: Makefile,v 1.3 2011/06/17 13:42:56 taca Exp $

DISTNAME=	test-unit-2.3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

pre-configure:
	${MV} ${WRKSRC}/bin/testrb ${WRKSRC}/bin/testrb2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
