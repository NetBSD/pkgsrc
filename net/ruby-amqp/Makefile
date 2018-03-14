# $NetBSD: Makefile,v 1.24 2018/03/14 15:10:47 taca Exp $

DISTNAME=	amqp-1.8.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=2.0.1:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
