# $NetBSD: Makefile,v 1.25 2003/10/03 14:48:40 salo Exp $
#

DISTNAME=		jpegsrc.v6b
PKGNAME=		jpeg-6b
PKGREVISION=		1
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/graphics/jpeg/ \
			ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=		mycroft@NetBSD.org
HOMEPAGE=		http://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static

INSTALL_TARGET=		install install-lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/jpeg

.include "../../mk/bsd.pkg.mk"
