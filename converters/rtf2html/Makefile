# $NetBSD: Makefile,v 1.7 2003/07/17 21:27:34 grant Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.45.free.net/~vitus/ice/misc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.45.free.net/~vitus/ice/catdoc/
COMMENT=	Rich Text to HTML file converter

USE_BUILDLINK2=	# defined
ALL_TARGET=	rtf2html
MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
