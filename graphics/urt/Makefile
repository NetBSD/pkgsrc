# $NetBSD: Makefile,v 1.17 2001/02/16 15:22:34 wiz Exp $
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

#DEPENDS+=	tiff-*:../tiff	# netpbm will pull in tiff.
DEPENDS+=	netpbm-9.*:../netpbm

EXTRACT_ONLY=	urt-3.1b.tar.Z

USE_X11=	yes
NO_WRKSUBDIR=   yes
CONFIGURE_SCRIPT=./Configure
CONFIGURE_ARGS=	config/urt
HAS_CONFIGURE=	yes
MAKEFILE=	makefile
ALL_TARGET=

post-install:
	${MKDIR} ${PREFIX}/share/doc/urt ${PREFIX}/share/examples/urt
	cd ${PREFIX}/share/doc/urt && (\
	    ${GTAR} xf ${DISTDIR}/urt-doc.tar; \
	    cd doc; \
	    ${FIND} -d . | cpio -dump ..; \
	    cd ..; \
	    ${RM} -rf doc)
	cd ${PREFIX}/share/examples/urt && (\
	    ${GTAR} xf ${DISTDIR}/urt-img.tar; \
	    ${CHOWN} -R root:wheel . ; \
	    ${FIND} . -type d -exec ${CHMOD} 775 '{}' \; ; \
	    ${FIND} . -type f -exec ${CHMOD} 664 '{}' \;)

.include "../../mk/bsd.pkg.mk"
