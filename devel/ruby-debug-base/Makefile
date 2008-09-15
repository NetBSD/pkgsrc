# $NetBSD: Makefile,v 1.3 2008/09/15 09:03:58 taca Exp $

DISTNAME=	ruby-debug-base-0.10.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.datanoise.com/ruby-debug/
COMMENT=	Fast implementation of the standard Ruby debugger

DEPENDS+=	${RUBY_PKGPREFIX}-linecache>=0.3:../../devel/ruby-linecache

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
