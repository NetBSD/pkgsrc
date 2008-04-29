# $NetBSD: Makefile,v 1.3 2008/04/29 18:39:06 jlam Exp $

DISTNAME=	sequel_core-1.5.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Core components for Sequel

DEPENDS+=	${RUBY_PKGPREFIX}-metaid>=1.0:../../devel/ruby-metaid

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
