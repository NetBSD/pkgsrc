# $NetBSD: Makefile,v 1.44 2026/02/17 13:44:26 taca Exp $

DISTNAME=	mocha-3.0.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mocha.jamesmead.org/
COMMENT=	Ruby library for mocking and stubbing
LICENSE=	ruby-license OR mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.5:../../devel/ruby-ruby2_keywords

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
