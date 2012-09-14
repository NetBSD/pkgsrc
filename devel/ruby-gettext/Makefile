# $NetBSD: Makefile,v 1.16 2012/09/14 16:02:44 taca Exp $

DISTNAME=	gettext-2.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license OR gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale

OVERRIDE_GEMSPEC=	:files po/de/gettext.po.bak= po/gettext.pot~=

pre-configure:
	cd ${WRKSRC}; ${FIND} . -type f -print | ${XARGS} ${CHMOD} g-w
	${RM} -f ${WRKSRC}/po/de/gettext.po.bak ${WRKSRC}/po/gettext.pot~

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
