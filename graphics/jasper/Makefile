# $NetBSD: Makefile,v 1.14 2004/02/14 17:21:42 jlam Exp $
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
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--enable-shared --without-x --disable-opengl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jasper
.for doc in ChangeLog LICENSE NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/jasper
.endfor

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
