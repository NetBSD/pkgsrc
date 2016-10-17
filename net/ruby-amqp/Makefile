# $NetBSD: Makefile,v 1.21 2016/10/17 14:35:41 taca Exp $

DISTNAME=	amqp-1.6.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=2.0.1:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
