# $NetBSD: Makefile,v 1.2 2017/06/12 14:40:38 taca Exp $

DISTNAME=	chef-config-13.1.31
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef
COMMENT=	Chef's default configuration and config loading
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.0<3:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.0<3:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-fuzzyurl>=0:../../textproc/ruby-fuzzyurl
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
