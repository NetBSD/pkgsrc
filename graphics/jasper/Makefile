# $NetBSD: Makefile,v 1.41 2016/02/25 08:27:03 jperkin Exp $

DISTNAME=	jasper-1.900.1
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.ece.uvic.ca/~mdadams/jasper/software/
EXTRACT_SUFX=	.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ece.uvic.ca/~mdadams/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --without-x --disable-opengl

# The solaris stdbool.h requires c99 which is fine for jasper, but
# not so good for things that depend upon jasper.  See PR#43901
CONFIGURE_ENV.SunOS+=	ac_cv_header_stdbool_h=no

INSTALLATION_DIRS+=	share/doc/jasper

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/jasper.pdf ${DESTDIR}${PREFIX}/share/doc/jasper
	${INSTALL_DATA} ${WRKSRC}/doc/jpeg2000.pdf ${DESTDIR}${PREFIX}/share/doc/jasper

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
