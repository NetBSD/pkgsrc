# $NetBSD: Makefile,v 1.15 2008/03/03 05:51:08 jlam Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.45.free.net/~vitus/ice/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.45.free.net/~vitus/ice/catdoc/
COMMENT=	Rich Text to HTML file converter

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	rtf2html
MAKE_FLAGS+=	CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
