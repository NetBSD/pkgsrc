# $NetBSD: Makefile,v 1.6 2008/09/15 15:41:53 taca Exp $

DISTNAME=	mailfactory-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/mailfactory/
COMMENT=	MIME email message generator for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.13.1:../../mail/ruby-mime-types

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
