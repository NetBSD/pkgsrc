# $NetBSD: Makefile,v 1.2 2009/06/13 06:46:48 rillig Exp $

DISTNAME=	pathname2-1.6.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Alternate implementation of the Pathname library

GEM_BUILD=	gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-facade>=1.0.1:../../devel/ruby-facade

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
