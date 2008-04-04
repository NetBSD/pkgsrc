# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:16:20 jlam Exp $

DISTNAME=	sequel_model-0.5.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Model components for Sequel

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-assistance>=0.1.2:../../devel/ruby-assistance
DEPENDS+=	${RUBY_PKGPREFIX}-sequel-core>=1.0:../../databases/ruby-sequel-core

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
