# $NetBSD: Makefile,v 1.2 2010/02/16 03:11:52 taca Exp $

DISTNAME=	gettext_activerecord-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-gettext.html
COMMENT=	Localization for ActiveRecord using Ruby-GetText-Package
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=2.1.0:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.3.2:../../databases/ruby-activerecord

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
