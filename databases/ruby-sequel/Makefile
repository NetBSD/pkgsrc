# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:16:06 jlam Exp $

DISTNAME=	sequel-1.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.rubyforge.org/
COMMENT=	Database toolkit for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-sequel-core>=1.3:../../databases/ruby-sequel-core
DEPENDS+=	${RUBY_PKGPREFIX}-sequel-model>=0.5.0.2:../../databases/ruby-sequel-model

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
