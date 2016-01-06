# $NetBSD: Makefile,v 1.10 2016/01/06 14:40:03 taca Exp $

DISTNAME=	test-unit-notify-1.0.4
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit-notify
COMMENT=	Test result notify extension for Ruby Test::Util
LICENSE=	gnu-lgpl-v2.1 # or later

USE_LANGUAGES=	# empty

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "200" || ${RUBY_VER} == "21"
DEPENDS+=	${RUBY_PKGPREFIX}-test-unit>=2.4.9:../../devel/ruby-test-unit
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
