# $NetBSD: Makefile,v 1.3 2008/04/29 17:36:28 jlam Exp $

DISTNAME=	mailfactory-1.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MIME email message generator for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.13.1:../../mail/ruby-mime-types

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
