# $NetBSD: Makefile,v 1.4 2010/09/07 17:20:25 taca Exp $

DISTNAME=	ruby-debug-base-0.10.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.datanoise.com/ruby-debug/
COMMENT=	Fast implementation of the standard Ruby debugger

DEPENDS+=	${RUBY_PKGPREFIX}-linecache>=0.3:../../devel/ruby-linecache

RUBY_VERSION_SUPPORTED= 18

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
