# $NetBSD: Makefile,v 1.1.1.1 2010/03/02 11:48:02 obache Exp $

DISTNAME=	termcolor-1.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/termcolor/
COMMENT=	ANSI color formatting like HTML for output in terminal

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
