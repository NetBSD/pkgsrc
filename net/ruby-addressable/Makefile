# $NetBSD: Makefile,v 1.3 2010/12/04 04:13:50 taca Exp $

DISTNAME=	addressable-2.2.2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://addressable.rubyforge.org/
COMMENT=	Replacement for the URI Implementation of standard librrary
LICENSE=	mit

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.0.8:../../devel/ruby-rspec
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=0.3.2:../../misc/ruby-launchy
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.2:../../textproc/ruby-diff-lcs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
