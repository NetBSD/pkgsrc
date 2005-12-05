# $NetBSD: Makefile,v 1.40 2005/12/05 20:50:23 rillig Exp $

DISTNAME=	urt
PKGNAME=	urt-3.1b1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.utah.edu/pub/dept/OLD/pub/
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar urt-img.tar

PATCH_SITES=	ftp://ptolemy.berkeley.edu/pub/misc/urt/
PATCHFILES=	urt-3.1b-3.1b1.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Toolkit and library for raster image processing

EXTRACT_ONLY=	urt-3.1b.tar.Z

WRKSRC=		${WRKDIR}
USE_LIBTOOL=	yes
CONFIGURE_SCRIPT=./Configure
CONFIGURE_ARGS+=	config/urt
HAS_CONFIGURE=	yes
MAKEFILE=	makefile
BUILD_TARGET=

post-extract:
	${CHMOD} 644 ${WRKSRC}/man/man1/rletotarga.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/urt ${PREFIX}/share/examples/urt
	cd ${PREFIX}/share/doc/urt && (\
	    ${PAX} -r -p m -s '/doc/./' -f ${DISTDIR}/urt-doc.tar; )
	cd ${PREFIX}/share/examples/urt && (\
	    ${PAX} -r -p m -f ${DISTDIR}/urt-img.tar; \
	    ${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} . ; \
	    ${FIND} . -type d -exec ${CHMOD} 755 '{}' \; ; \
	    ${FIND} . -type f -exec ${CHMOD} 644 '{}' \;)

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
