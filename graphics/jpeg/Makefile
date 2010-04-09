# $NetBSD: Makefile,v 1.41 2010/04/09 20:00:02 drochner Exp $
#

DISTNAME=		jpegsrc.v8a
PKGNAME=		jpeg-8a
CATEGORIES=		graphics
MASTER_SITES=		http://www.ijg.org/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin include share/doc/jpeg

CONFIGURE_ARGS+=	--disable-ld-version-script

post-extract:
	${CP} ${FILESDIR}/jpegexiforient.c ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/exifautotran ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jpegint.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/jpeg

.include "../../mk/bsd.pkg.mk"
