# $NetBSD: Makefile,v 1.17 2010/09/07 17:20:24 taca Exp $

DISTNAME=	uconv-0.4.12
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#uconv
COMMENT=	Unicode conversion library with Japanese codesets support

PKG_DESTDIR_SUPPORT=	destdir

# Depends on Ruby's internal and use 1.9's encoding support.
RUBY_VERSION_SUPPORTED= 18
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/uconv

INSTALLATION_DIRS=	${RUBY_DOC}/uconv
INSTALL_TARGET=		site-install

DOCS=			README README.ja

post-install:
.for f in ${DOCS}
	cd ${WRKSRC}; ${INSTALL_DATA} ${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/uconv
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
