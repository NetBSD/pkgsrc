# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:18:33 jlam Exp $

DISTNAME=	rspec-1.1.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rspec.info/
COMMENT=	Behaviour Driven Development framework for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.2:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-heckle>=1.4.1:../../devel/ruby-heckle
DEPENDS+=	${RUBY_PKGPREFIX}-rcov>=0.8.1.2.0:../../devel/ruby-rcov

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
