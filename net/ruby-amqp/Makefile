# $NetBSD: Makefile,v 1.9 2012/09/16 07:27:50 taca Exp $

DISTNAME=	amqp-0.9.7
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

# ruby-amq-client depends on ruby-eventmachine and ruby-amq-protocol 
#DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
#DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=0.9.4:../../net/ruby-amq-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-amq-client>=0.9.4<0.10:../../net/ruby-amq-client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
