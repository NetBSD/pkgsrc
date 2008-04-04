# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:18:14 jlam Exp $

DISTNAME=	ParseTree-2.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://parsetree.rubyforge.org/
COMMENT=	Extract and enumerate Ruby parse trees

DEPENDS+=	${RUBY_PKGPREFIX}-inline>=3.6.0:../../devel/ruby-inline
DEPENDS+=	hoe>=1.4.0:../../devel/hoe

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
