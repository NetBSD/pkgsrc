# $NetBSD: Makefile,v 1.8 2020/09/14 16:17:42 taca Exp $

DISTNAME=	mixlib-config-3.0.9
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/mixlib-config
COMMENT=	Class based configuration library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-tomlrb>=0:../../devel/ruby-tomlrb

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
