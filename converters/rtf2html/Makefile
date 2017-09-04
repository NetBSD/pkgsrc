# $NetBSD: Makefile,v 1.17 2017/09/04 18:00:51 wiz Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.45.free.net/~vitus/ice/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.45.free.net/~vitus/ice/catdoc/
COMMENT=	Rich Text to HTML file converter

BUILD_TARGET=	rtf2html
MAKE_FLAGS+=	CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
