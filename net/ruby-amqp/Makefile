# $NetBSD: Makefile,v 1.12 2013/03/12 13:26:26 taca Exp $

DISTNAME=	amqp-0.9.10
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

# ruby-amq-client depends on ruby-eventmachine and ruby-amq-protocol 
#DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=1.2.0<1.3:../../net/ruby-amq-client
#DEPENDS+=	${RUBY_PKGPREFIX}-amq-client>=0.9.12<0.10:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
