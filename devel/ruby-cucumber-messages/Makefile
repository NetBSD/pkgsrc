# $NetBSD: Makefile,v 1.8 2020/09/13 15:33:54 taca Exp $

DISTNAME=	cucumber-messages-13.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-messages-ruby
COMMENT=	Cucumber Messages for Ruby (Protocol Buffers)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-protobuf-cucumber>=3.10.4<4:../../devel/ruby-protobuf-cucumber

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
