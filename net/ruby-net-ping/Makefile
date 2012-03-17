# $NetBSD: Makefile,v 1.4 2012/03/17 16:58:19 taca Exp $

DISTNAME=	net-ping-1.5.3
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyforge.org/projects/shards
COMMENT=	Ping interface for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ldap>=0.2.2<0.4:../../net/ruby-net-ldap
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.0.0:../../devel/ruby-ffi

OVERRIDE_GEMSPEC+=	ruby-net-ldap~>0.2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
