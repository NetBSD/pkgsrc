# $NetBSD: Makefile,v 1.1.1.1 2010/03/09 12:42:50 fhajny Exp $

DISTNAME=	gemcutter-0.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/gemcutter
COMMENT=	Commands to interact with RubyGems.org
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-json-pure-[0-9]*:../../textproc/ruby-json-pure

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
