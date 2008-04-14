# $NetBSD: Makefile,v 1.2 2008/04/14 21:33:04 jlam Exp $

DISTNAME=	ruby-debug-0.10.1
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.datanoise.com/ruby-debug/
COMMENT=	Command line interface for ruby-debug

DEPENDS+=	${RUBY_PKGPREFIX}-columnize>=0.1:../../misc/ruby-columnize
DEPENDS+=	${RUBY_PKGPREFIX}-ruby-debug-base-0.10.1{,nb[0-9]*}:../../devel/ruby-debug-base

post-extract:
	cd ${WRKSRC} && echo ${PKGVERSION_NOREV} > VERSION

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
