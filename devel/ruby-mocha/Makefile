# $NetBSD: Makefile,v 1.38 2024/06/30 16:11:46 taca Exp $

DISTNAME=	mocha-2.4.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mocha.jamesmead.org/
COMMENT=	Ruby library for mocking and stubbing
LICENSE=	ruby-license OR mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.5:../../devel/ruby-ruby2_keywords

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
