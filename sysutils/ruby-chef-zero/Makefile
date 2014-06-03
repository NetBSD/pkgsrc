# $NetBSD: Makefile,v 1.1 2014/06/03 14:30:36 jperkin Exp $

DISTNAME=	chef-zero-2.0.2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef-zero
COMMENT=	Simple fast-start in-memory Chef server
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6.0:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=2.0.5:../../misc/ruby-hashie2
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.5.2:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
