# $NetBSD: Makefile,v 1.6 2011/09/12 13:29:22 taca Exp $

DISTNAME=	amqp-0.8.0
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/tmm1/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.4:../../devel/ruby-eventmachine

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
