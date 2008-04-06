# $NetBSD: Makefile,v 1.1.1.1 2008/04/06 23:04:42 seb Exp $

DISTNAME=	ruby-debug-ide-0.1.10
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://debug-commons.rubyforge.org/
COMMENT=	IDEs interface to ruby-debug

DEPENDS+=	${RUBYGEM_PKGPREFIX}-ruby-debug-base-[0-9]*:../../devel/ruby-debug-base

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
