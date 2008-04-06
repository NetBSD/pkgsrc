# $NetBSD: Makefile,v 1.1.1.1 2008/04/06 23:03:58 seb Exp $

DISTNAME=	ruby-debug-0.10.0
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.datanoise.com/ruby-debug/
COMMENT=	Command line interface for ruby-debug

DEPENDS+=	${RUBY_PKGPREFIX}-ruby-debug-base-0.10.0{,nb[0-9]*}:../../devel/ruby-debug-base

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
