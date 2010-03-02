# $NetBSD: Makefile,v 1.1.1.1 2010/03/02 12:10:22 obache Exp $

DISTNAME=	rubytter-1.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rubytter/
COMMENT=	Simple twitter library

DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.1.3:../../textproc/ruby-json

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
