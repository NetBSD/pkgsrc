# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:16:13 jlam Exp $

DISTNAME=	sequel_core-1.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Core components for Sequel

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-metaid>=1.0:../../devel/ruby-metaid
DEPENDS+=	${RUBY_PKGPREFIX}-assistance>=0.1:../../devel/ruby-assistance
DEPENDS+=	${RUBY_PKGPREFIX}-inline>=3.6.6:../../devel/ruby-inline
DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=2.1.1:../../devel/ruby-parsetree
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.8:../../devel/ruby2ruby

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
