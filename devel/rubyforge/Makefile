# $NetBSD: Makefile,v 1.7 2010/09/10 06:37:04 taca Exp $

DISTNAME=	rubyforge-2.0.4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/codeforpeople/
COMMENT=	Simplistic script automating RubyForge operations
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.7:../../textproc/ruby-json-pure

CONFLICTS+=	ruby[1-9][0-9]-rubyforge-[0-9]*

pre-build:
	cd ${WRKSRC}; ${CHMOD} -R g-w .

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
