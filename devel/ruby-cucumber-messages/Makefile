# $NetBSD: Makefile,v 1.3 2020/01/18 15:22:56 taca Exp $

DISTNAME=	cucumber-messages-9.0.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-messages-ruby
COMMENT=	Cucumber Messages for Ruby (Protocol Buffers)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-google-protobuf>=3.6.1<3.9:../../devel/ruby-google-protobuf

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
