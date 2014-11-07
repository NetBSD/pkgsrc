# $NetBSD: Makefile,v 1.4 2014/11/07 11:08:12 obache Exp $

DISTNAME=	test-unit-notify-1.0.4
CATEGORIES=	devel

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://test-unit.rubyforge.org/
COMMENT=	Test result notify extension for Ruby Test::Util
LICENSE=	gnu-lgpl-v2.1 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-test-unit>=2.4.9:../../devel/ruby-test-unit

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
