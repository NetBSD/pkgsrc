# $NetBSD: Makefile,v 1.11 2005/03/24 21:12:52 wiz Exp $

DISTNAME=	uconv-0.4.12
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#uconv
COMMENT=	Unicode conversion library with Japanese codesets support

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/uconv

INSTALL_TARGET=		site-install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/uconv
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/uconv
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_DOCDIR}/uconv

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
