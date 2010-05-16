# $NetBSD: Makefile,v 1.6 2010/05/16 12:22:43 obache Exp $

DISTNAME=		net-irc-0.0.9
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		chat

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://lowreal.rubyforge.org/net-irc/
COMMENT=		Ruby IRC library
LICENSE=		ruby-license

GEM_BUILD=		gemspec

REPLACE_RUBY=		lib/net/irc.rb

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
