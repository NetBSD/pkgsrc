# $NetBSD: Makefile,v 1.2 2010/06/09 10:42:07 fhajny Exp $

DISTNAME=	amqp-0.6.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/tmm1/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.4:../../devel/ruby-eventmachine

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
