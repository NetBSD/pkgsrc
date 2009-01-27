# $NetBSD: Makefile,v 1.1.1.1 2009/01/27 00:12:27 ahoka Exp $

DISTNAME=	pathname2-1.6.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Alternate implementation of the Pathname library

GEM_BUILD=	gemspec

DEPENDS+=       ${RUBY_PKGPREFIX}-facade>=1.0.1:../../devel/ruby-facade

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
