# $NetBSD: Makefile,v 1.6 2011/11/08 15:45:43 taca Exp $

DISTNAME=	test-unit-2.3.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

pre-configure:
	${CP} ${FILESDIR}/gemspec ${GEM_SPECFILE}
	${MV} ${WRKSRC}/bin/testrb ${WRKSRC}/bin/testrb2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
