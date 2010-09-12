# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 01:34:20 taca Exp $

DISTNAME=	test-unit-2.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

pre-configure:
	${MV} ${WRKSRC}/bin/testrb ${WRKSRC}/bin/testrb2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
