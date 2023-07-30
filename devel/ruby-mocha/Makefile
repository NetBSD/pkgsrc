# $NetBSD: Makefile,v 1.35 2023/07/30 04:03:31 taca Exp $

DISTNAME=	mocha-2.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mocha.jamesmead.org/
COMMENT=	Ruby library for mocking and stubbing
LICENSE=	ruby-license OR mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.5:../../devel/ruby-ruby2_keywords

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
