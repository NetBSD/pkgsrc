# $NetBSD: Makefile,v 1.36 2007/06/05 22:07:25 tnn Exp $
#

DISTNAME=		jpegsrc.v6b
PKGNAME=		jpeg-6b
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/graphics/jpeg/ \
			ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static

INSTALL_TARGET=		install install-lib
INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

post-extract:
	${CP} ${FILESDIR}/jpegexiforient.c ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/exifautotran ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/*.doc ${DESTDIR}${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/jpegint.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
