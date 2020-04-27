# $NetBSD: Makefile,v 1.7 2020/04/27 04:55:32 taca Exp $

DISTNAME=	cucumber-messages-12.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-messages-ruby
COMMENT=	Cucumber Messages for Ruby (Protocol Buffers)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-protobuf-cucumber>=3.10.4<4:../../devel/ruby-protobuf-cucumber

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
