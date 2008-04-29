# $NetBSD: Makefile,v 1.3 2008/04/29 18:39:02 jlam Exp $

DISTNAME=	sequel-1.5.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Model classes for the Sequel Database Toolkit

DEPENDS+=	${RUBY_PKGPREFIX}-sequel-core>=1.5.0:../../databases/ruby-sequel-core

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
