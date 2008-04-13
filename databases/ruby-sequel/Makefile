# $NetBSD: Makefile,v 1.2 2008/04/13 06:56:30 jlam Exp $

DISTNAME=	sequel-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Model classes for the Sequel Database Toolkit

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-assistance>=0.1.2:../../devel/ruby-assistance
DEPENDS+=	${RUBY_PKGPREFIX}-sequel-core>=1.4.0:../../databases/ruby-sequel-core

# Remove originals of patched files so they aren't included in the gem.
pre-build:
	find ${WRKSRC} -name "*.orig" | xargs rm -f

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
