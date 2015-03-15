# $NetBSD: Makefile,v 1.6 2015/03/15 18:46:55 hiramatsu Exp $

DISTNAME=	test-unit-notify-1.0.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://test-unit.rubyforge.org/
COMMENT=	Test result notify extension for Ruby Test::Util
LICENSE=	gnu-lgpl-v2.1 # or later

RUBY_VERSION_SUPPORTED=	200 21

DEPENDS+=	${RUBY_PKGPREFIX}-test-unit>=2.4.9:../../devel/ruby-test-unit

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
