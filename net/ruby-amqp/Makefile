# $NetBSD: Makefile,v 1.15 2013/09/15 18:30:48 taca Exp $

DISTNAME=	amqp-1.0.2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

# ruby-amq-client depends on ruby-eventmachine and ruby-amq-protocol
#DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=1.3.0:../../net/ruby-amq-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-amq-client>=1.0.2:../../net/ruby-amq-client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
