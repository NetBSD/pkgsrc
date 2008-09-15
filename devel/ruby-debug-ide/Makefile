# $NetBSD: Makefile,v 1.4 2008/09/15 09:05:24 taca Exp $

DISTNAME=	ruby-debug-ide-0.3.0
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://debug-commons.rubyforge.org/
COMMENT=	IDEs interface to ruby-debug

DEPENDS+=	${RUBYGEM_PKGPREFIX}-ruby-debug-base-[0-9]*:../../devel/ruby-debug-base

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
