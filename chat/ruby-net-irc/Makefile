# $NetBSD: Makefile,v 1.2 2009/05/14 09:16:39 obache Exp $

DISTNAME=		net-irc-0.0.7
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		chat

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://coderepos.org/share/browser/lang/ruby/net-irc
COMMENT=		Ruby IRC library

GEM_BUILD=		gemspec

REPLACE_RUBY=		lib/net/irc.rb

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
