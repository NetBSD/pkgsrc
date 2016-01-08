# $NetBSD: Makefile,v 1.1 2016/01/08 12:53:11 fhajny Exp $
#
DISTNAME=	zookeeper-1.4.11
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/zk-ruby/zookeeper
COMMENT=	Zookeeper bindings for Ruby
LICENSE=	mit

.include "../../devel/libzookeeper/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
