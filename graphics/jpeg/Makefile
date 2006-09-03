# $NetBSD: Makefile,v 1.34 2006/09/03 00:56:29 wiz Exp $
#

DISTNAME=		jpegsrc.v6b
PKGNAME=		jpeg-6b
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/graphics/jpeg/ \
			ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static

INSTALL_TARGET=		install install-lib
INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/jpegint.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
