# $NetBSD: Makefile,v 1.10 2012/10/23 17:19:06 asau Exp $

DISTNAME=	amqp-0.9.7
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

# ruby-amq-client depends on ruby-eventmachine and ruby-amq-protocol 
#DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
#DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=0.9.4:../../net/ruby-amq-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-amq-client>=0.9.4<0.10:../../net/ruby-amq-client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
