# $NetBSD: Makefile,v 1.6 2009/11/23 13:39:42 fhajny Exp $

DISTNAME=	rubyforge-2.0.3
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/codeforpeople/
COMMENT=	Simplistic script automating RubyForge operations
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.7:../../textproc/ruby-json-pure

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
