# $NetBSD: Makefile,v 1.2 2008/04/14 21:33:01 jlam Exp $

DISTNAME=	ruby-debug-base-0.10.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.datanoise.com/ruby-debug/
COMMENT=	Fast implementation of the standard Ruby debugger

DEPENDS+=	${RUBY_PKGPREFIX}-linecache>=0.3:../../devel/ruby-linecache

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
