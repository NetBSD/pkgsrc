# $NetBSD: Makefile,v 1.9 2011/11/23 05:32:22 taca Exp $

DISTNAME=	rubyforge-2.0.4
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/codeforpeople/
COMMENT=	Simplistic script automating RubyForge operations
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-rubyforge-[0-9]* rubyforge-[0-9]*

RUBY_JSON_REQD=	1.1.7
RUBY_JSON_TYPE=	pure

pre-build:
	cd ${WRKSRC}; ${CHMOD} -R g-w .

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
