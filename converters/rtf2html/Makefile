# $NetBSD: Makefile,v 1.12 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.45.free.net/~vitus/ice/misc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.45.free.net/~vitus/ice/catdoc/
COMMENT=	Rich Text to HTML file converter

BUILD_TARGET=	rtf2html
MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
