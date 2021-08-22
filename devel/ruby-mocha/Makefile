# $NetBSD: Makefile,v 1.30 2021/08/22 13:48:10 taca Exp $

DISTNAME=	mocha-1.13.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gofreerange.com/mocha/docs/
COMMENT=	Ruby library for mocking and stubbing
LICENSE=	ruby-license OR mit

DEPENDS+=	${RUBY_PKGPREFIX}-metaclass>=0.0.1<0.1:../../devel/ruby-metaclass

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
