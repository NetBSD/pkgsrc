# $NetBSD: Makefile,v 1.5 2008/05/01 17:51:14 jlam Exp $

DISTNAME=	sequel_core-1.5.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Core components for Sequel

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-metaid>=1.0:../../devel/ruby-metaid

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
