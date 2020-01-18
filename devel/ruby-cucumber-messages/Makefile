# $NetBSD: Makefile,v 1.4 2020/01/18 16:26:43 taca Exp $

DISTNAME=	cucumber-messages-9.0.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-messages-ruby
COMMENT=	Cucumber Messages for Ruby (Protocol Buffers)
LICENSE=	mit

DEPENDS+=	json>=2.3.0<2.4:../../textproc/ruby-json
DEPENDS+=	protobuf-cucumber>=3.10.4<3.11:../../devel/ruby-protobuf-cucumber

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
