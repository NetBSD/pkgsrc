# $NetBSD: Makefile,v 1.30 2004/10/03 00:14:54 tv Exp $
#

DISTNAME=		jpegsrc.v6b
PKGNAME=		jpeg-6b
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/graphics/jpeg/ \
			ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=		mycroft@NetBSD.org
HOMEPAGE=		http://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static

INSTALL_TARGET=		install install-lib
INSTALLATION_DIRS=	bin lib include man/man1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/jpeg

.include "../../mk/bsd.pkg.mk"
