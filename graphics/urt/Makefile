# $NetBSD: Makefile,v 1.68 2023/10/21 17:10:43 gdt Exp $

DISTNAME=	urt
PKGNAME=	urt-3.1b1
PKGREVISION=	19
CATEGORIES=	graphics
#MASTER_SITES=	ftp://ftp.iastate.edu/pub/utah-raster/
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar.Z urt-img.tar.Z

PATCH_SITES=		http://www.funet.fi/pub/graphics/packages/urt/rel2/
PATCHFILES=		urt-3.1b-3.1b1.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.utah.edu/gdc/projects/urt/
COMMENT=	Toolkit and library for raster image processing

EXTRACT_ONLY=	urt-3.1b.tar.Z

WRKSRC=			${WRKDIR}
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	config/urt
HAS_CONFIGURE=		yes
MAKE_FILE=		makefile
BUILD_TARGET=		# the default one

AUTO_MKDIRS=			yes

post-extract:
	chmod 644 ${WRKSRC}/man/man1/rletotarga.1

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	config/urt
SUBST_SED.man=		-e 's,^\(\#defpath MAN_DEST\).*,\1 ${PREFIX}/${PKGMANDIR},'

post-install:
	cd ${DESTDIR}${PREFIX}/share/doc/urt && \
	    pax -z -r -p m -s '/doc/./' -f ${DISTDIR}/urt-doc.tar.Z
	cd ${DESTDIR}${PREFIX}/share/examples/urt && \
	    pax -z -r -p m -f ${DISTDIR}/urt-img.tar.Z
	cd ${DESTDIR}${PREFIX} && \
	    chown -R ${ROOT_USER}:${ROOT_GROUP} share/doc/urt share/examples/urt && \
	    find share/doc/urt share/examples/urt -type d -print | xargs chmod 755 && \
	    find share/doc/urt share/examples/urt -type f -print | xargs chmod 444

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
