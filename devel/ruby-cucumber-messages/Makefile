# $NetBSD: Makefile,v 1.1 2018/10/28 15:37:51 taca Exp $

DISTNAME=	cucumber-messages-1.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-messages-ruby
COMMENT=	Cucumber Messages for Ruby (Protocol Buffers)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-google-protobuf>=3.6.1<3.7:../../devel/ruby-google-protobuf

OVERRIDE_GEMSPEC+=	google-protobuf>=3.6.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
