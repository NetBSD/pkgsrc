# $NetBSD: Makefile,v 1.9 2003/10/08 02:21:32 danw Exp $
#

DISTNAME=		jasper-1.600.0
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.ece.uvic.ca/~mdadams/jasper/software/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ece.uvic.ca/~mdadams/jasper/
COMMENT=		Software-based reference implementation of the JPEG-2000 codec

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--enable-shared --without-x --disable-opengl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jasper
.for doc in ChangeLog LICENSE NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/jasper
.endfor

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
