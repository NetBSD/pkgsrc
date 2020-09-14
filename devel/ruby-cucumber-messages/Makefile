# $NetBSD: Makefile,v 1.9 2020/09/14 16:11:14 taca Exp $

DISTNAME=	cucumber-messages-13.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-messages-ruby
COMMENT=	Cucumber Messages for Ruby (Protocol Buffers)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-protobuf-cucumber>=3.10.4<4:../../devel/ruby-protobuf-cucumber

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
