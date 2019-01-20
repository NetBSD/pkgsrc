# $NetBSD: Makefile,v 1.26 2019/01/20 13:51:15 taca Exp $

DISTNAME=	mocha-1.8.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gofreerange.com/mocha/docs/
COMMENT=	Ruby library for mocking and stubbing
LICENSE=	ruby-license OR mit

DEPENDS+=	${RUBY_PKGPREFIX}-metaclass>=0.0.1<0.1:../../devel/ruby-metaclass

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
