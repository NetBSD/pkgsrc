# $NetBSD: Makefile,v 1.10 2015/09/15 20:54:44 joerg Exp $

DISTNAME=	amq-client-1.0.4
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ruby-amqp/amq-client
COMMENT=	Fully-featured, low-level AMQP 0.9.1 client
LICENSE=	mit

RUBY_VERSION_SUPPORTED=	200 21 22

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=1.9.0:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
