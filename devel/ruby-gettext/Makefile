# $NetBSD: Makefile,v 1.12 2012/03/12 15:41:37 taca Exp $

DISTNAME=	gettext-2.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-gettext.html
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale

pre-configure:
	cd ${WRKSRC}; ${FIND} . -type f -print | ${XARGS} ${CHMOD} g-w
	${CHMOD} -x ${WRKSRC}/samples/makemo.rb
	${RM} -f ${WRKSRC}/samples/cgi/po/bg/#main.po#

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
