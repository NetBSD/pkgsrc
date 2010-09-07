# $NetBSD: Makefile,v 1.5 2010/09/07 17:20:25 taca Exp $

DISTNAME=	ruby-debug-ide-0.3.0
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://debug-commons.rubyforge.org/
COMMENT=	IDEs interface to ruby-debug

DEPENDS+=	${RUBYGEM_PKGPREFIX}-ruby-debug-base-[0-9]*:../../devel/ruby-debug-base

RUBY_VERSION_SUPPORTED= 18

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
