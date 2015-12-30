# $NetBSD: Makefile,v 1.9 2015/12/30 04:22:59 taca Exp $

DISTNAME=	test-unit-notify-1.0.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit-notify
COMMENT=	Test result notify extension for Ruby Test::Util
LICENSE=	gnu-lgpl-v2.1 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-test-unit>=2.4.9:../../devel/ruby-test-unit

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
