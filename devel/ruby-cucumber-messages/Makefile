# $NetBSD: Makefile,v 1.2 2019/01/20 13:36:40 taca Exp $

DISTNAME=	cucumber-messages-2.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-messages-ruby
COMMENT=	Cucumber Messages for Ruby (Protocol Buffers)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-google-protobuf>=3.6.1<3.7:../../devel/ruby-google-protobuf

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
