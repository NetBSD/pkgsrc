# $NetBSD: Makefile,v 1.9 2022/08/11 13:31:21 taca Exp $

DISTNAME=	mixlib-config-3.0.27
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/mixlib-config
COMMENT=	Class based configuration library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-tomlrb>=0:../../devel/ruby-tomlrb

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
