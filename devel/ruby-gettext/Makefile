# $NetBSD: Makefile,v 1.9 2009/12/07 12:09:20 fhajny Exp $

DISTNAME=	gettext-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gettext.rubyforge.org/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
