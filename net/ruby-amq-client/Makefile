# $NetBSD: Makefile,v 1.5 2012/12/17 12:43:39 taca Exp $

DISTNAME=	amq-client-0.9.10
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ruby-amqp/amq-client
COMMENT=	Fully-featured, low-level AMQP 0.9.1 client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=0.9.4:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
