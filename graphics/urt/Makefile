# $NetBSD: Makefile,v 1.23 2001/12/05 15:00:46 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1998/02/11 08:48:26 tg Exp

DISTNAME=	urt
PKGNAME=	urt-3.1b1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.utah.edu/pub/dept/OLD/pub/
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar urt-img.tar

PATCH_SITES=	ftp://ptolemy.berkeley.edu/pub/misc/urt/
PATCHFILES=	urt-3.1b-3.1b1.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	packages@netbsd.org
COMMENT=	Utah raster toolkit - a toolkit and library for raster image processing

#DEPENDS+=	tiff-[0-9]*:../tiff	# netpbm will pull in tiff.
DEPENDS+=	netpbm-9.*:../netpbm

EXTRACT_ONLY=	urt-3.1b.tar.Z

USE_LIBTOOL=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}
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
	    ${FIND} -d . | cpio -dump ..; \
	    cd ..; \
	    ${RM} -rf doc)
	cd ${PREFIX}/share/examples/urt && (\
	    ${GTAR} xf ${DISTDIR}/urt-img.tar; \
	    ${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} . ; \
	    ${FIND} . -type d -exec ${CHMOD} 755 '{}' \; ; \
	    ${FIND} . -type f -exec ${CHMOD} 644 '{}' \;)

.include "../../mk/bsd.pkg.mk"
