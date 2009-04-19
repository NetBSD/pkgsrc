# $NetBSD: Makefile,v 1.1.1.1 2009/04/19 09:27:36 seb Exp $
#

DISTNAME=	rb-appscript-0.5.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rb-appscript/
COMMENT=	Ruby Apple event bridge

ONLY_FOR_PLATFORM=	Darwin-*-*

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
