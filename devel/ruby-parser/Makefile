# $NetBSD: Makefile,v 1.1.1.1 2009/11/23 14:04:10 fhajny Exp $

DISTNAME=	ruby_parser-2.0.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby_//}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://rubyforge.org/projects/parsetree/
COMMENT=	Ruby parser written in pure ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=3.0:../../devel/ruby-sexp-processor

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
