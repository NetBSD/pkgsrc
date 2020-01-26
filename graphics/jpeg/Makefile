# $NetBSD: Makefile,v 1.57 2020/01/26 17:31:22 rillig Exp $

DISTNAME=	jpegsrc.v9d
PKGNAME=	${DISTNAME:S/src.v/-/}
CATEGORIES=	graphics
MASTER_SITES=	http://www.ijg.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ijg.org/
COMMENT=	IJG's jpeg compression utilities

CONFLICTS=		libjpeg-turbo-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ld-version-script

INSTALLATION_DIRS=	bin include share/doc/jpeg

PKGCONFIG_OVERRIDE=	libjpeg.pc.in

TEST_TARGET=		test

post-extract:
	${CP} ${FILESDIR}/jpegexiforient.c ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/exifautotran ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jpegint.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/jpeg

.include "../../mk/bsd.pkg.mk"
