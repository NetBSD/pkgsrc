# $NetBSD: Makefile,v 1.17 2015/02/04 15:47:45 taca Exp $

DISTNAME=	amqp-1.5.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=1.9.2:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
