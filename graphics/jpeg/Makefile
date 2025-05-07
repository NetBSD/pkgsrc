# $NetBSD: Makefile,v 1.60 2025/05/07 09:13:54 jperkin Exp $

DISTNAME=	jpegsrc.v9f
PKGNAME=	${DISTNAME:S/src.v/-/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ijg.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ijg.org/
COMMENT=	IJG's jpeg compression utilities
LICENSE=	ijg

CONFLICTS=		libjpeg-turbo-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ld-version-script

INSTALLATION_DIRS=	bin include share/doc/jpeg

PKGCONFIG_OVERRIDE=	libjpeg.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${JPEG_DEFAULT:U} == "jpeg"
SUPERSEDES+=	libjpeg-turbo-[0-9]*
.endif

BUILD_DEFS+=		JPEG_DEFAULT

TEST_TARGET=		test

post-extract:
	${CP} ${FILESDIR}/jpegexiforient.c ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/exifautotran ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jpegint.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/jpeg

.include "../../mk/bsd.pkg.mk"
