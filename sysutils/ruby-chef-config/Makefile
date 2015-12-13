# $NetBSD: Makefile,v 1.1 2015/12/13 15:16:35 taca Exp $

DISTNAME=	chef-config-12.5.1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef
COMMENT=	Chef's default configuration and config loading
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.0<3:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.0<3:../../devel/ruby-mixlib-shellout

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
