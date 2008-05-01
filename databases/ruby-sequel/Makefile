# $NetBSD: Makefile,v 1.6 2008/05/01 17:51:13 jlam Exp $

DISTNAME=	sequel-1.5.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Model classes for the Sequel Database Toolkit

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-sequel-core>=1.5.1:../../databases/ruby-sequel-core

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
