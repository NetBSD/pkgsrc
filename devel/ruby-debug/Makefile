# $NetBSD: Makefile,v 1.4 2010/09/07 17:20:25 taca Exp $

DISTNAME=	ruby-debug-0.10.2
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.datanoise.com/ruby-debug/
COMMENT=	Command line interface for ruby-debug

DEPENDS+=	${RUBY_PKGPREFIX}-columnize>=0.1:../../misc/ruby-columnize
DEPENDS+=	${RUBY_PKGPREFIX}-ruby-debug-base>=0.10.2{,nb[0-9]*}:../../devel/ruby-debug-base

RUBY_VERSION_SUPPORTED= 18

post-extract:
	cd ${WRKSRC} && echo ${PKGVERSION_NOREV} > VERSION

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
