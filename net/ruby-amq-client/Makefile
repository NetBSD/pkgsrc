# $NetBSD: Makefile,v 1.12 2017/03/20 14:42:03 taca Exp $

DISTNAME=	amq-client-1.0.4
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-amqp/amq-client
COMMENT=	Fully-featured, low-level AMQP 0.9.1 client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=1.9.0:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
