# $NetBSD: Makefile,v 1.7 2011/12/16 15:41:11 taca Exp $

DISTNAME=	test-unit-2.4.3
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
