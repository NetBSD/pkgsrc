# $NetBSD: Makefile,v 1.5 2008/04/04 15:20:01 jlam Exp $

DISTNAME=	gem_plugin-0.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	misc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Gem-based plugin system

CONFLICTS+=	ruby[1-9]*-gem_plugin-[0-9]*

DEPENDS+=	rake>=0.7:../../devel/rake

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
