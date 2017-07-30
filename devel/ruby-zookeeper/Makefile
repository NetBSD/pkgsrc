# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:18 wiz Exp $
#
DISTNAME=	zookeeper-1.4.11
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zk-ruby/zookeeper
COMMENT=	Zookeeper bindings for Ruby
LICENSE=	mit

.include "../../devel/libzookeeper/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
