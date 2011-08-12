# $NetBSD: Makefile,v 1.5 2011/08/12 17:07:49 taca Exp $

DISTNAME=	amqp-0.7.4
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/tmm1/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.4:../../devel/ruby-eventmachine

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
