# $NetBSD: Makefile,v 1.37 2024/05/26 14:50:37 taca Exp $

DISTNAME=	mocha-2.3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mocha.jamesmead.org/
COMMENT=	Ruby library for mocking and stubbing
LICENSE=	ruby-license OR mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.5:../../devel/ruby-ruby2_keywords

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
