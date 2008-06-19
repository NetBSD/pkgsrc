# $NetBSD: Makefile,v 1.2 2008/06/19 15:08:23 taca Exp $

DISTNAME=	ruby-debug-ide-0.1.10
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

PATCH_ARGS+=	-d ${WRKDIR} --forward --quiet -E ${PATCH_STRIP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://debug-commons.rubyforge.org/
COMMENT=	IDEs interface to ruby-debug

DEPENDS+=	${RUBYGEM_PKGPREFIX}-ruby-debug-base-[0-9]*:../../devel/ruby-debug-base

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
