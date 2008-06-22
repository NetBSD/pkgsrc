# $NetBSD: Makefile,v 1.4 2008/06/22 16:09:01 taca Exp $

DISTNAME=	mailfactory-1.3.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MIME email message generator for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.13.1:../../mail/ruby-mime-types

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
