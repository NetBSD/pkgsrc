# $NetBSD: Makefile,v 1.32 2004/01/27 00:53:11 heinz Exp $

DISTNAME=	urt
PKGNAME=	urt-3.1b1
PKGREVISION=	3
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
USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
USE_X11=	yes
CONFIGURE_SCRIPT=./Configure
CONFIGURE_ARGS=	config/urt
HAS_CONFIGURE=	yes
MAKEFILE=	makefile
ALL_TARGET=

post-extract:
	${CHMOD} 644 ${WRKSRC}/man/man1/rletotarga.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/urt ${PREFIX}/share/examples/urt
	cd ${PREFIX}/share/doc/urt && (\
	    ${GTAR} xf ${DISTDIR}/urt-doc.tar; \
	    cd doc; \
	    ${FIND} -d . -print | cpio -dump ..; \
	    cd ..; \
	    ${RM} -rf doc)
	cd ${PREFIX}/share/examples/urt && (\
	    ${GTAR} xf ${DISTDIR}/urt-img.tar; \
	    ${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} . ; \
	    ${FIND} . -type d -exec ${CHMOD} 755 '{}' \; ; \
	    ${FIND} . -type f -exec ${CHMOD} 644 '{}' \;)

.include "../../graphics/netpbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
