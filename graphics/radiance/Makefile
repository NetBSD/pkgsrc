# $NetBSD: Makefile,v 1.2 2005/02/16 23:20:24 jschauma Exp $
#

DISTNAME=	rad3R6P1
PKGNAME=	radiance-3.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.radiance-online.org/software/non-cvs/	\
		http://www.radiance-online.org/software/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}supp${EXTRACT_SUFX}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.radiance-online.org/
COMMENT=	Physically-based, image-generating, backward raytracer

WRKSRC=		${WRKDIR}/ray
USE_BUILDLINK3=	YES
USE_X11=	YES

LICENSE=	radiance-license

PATCHEES=	makeall ./src/rt/Rmakefile ./src/util/Rmakefile		\
		./src/ot/Rmakefile ./src/meta/Rmakefile 		\
		./src/hd/Rmakefile ./src/gen/Rmakefile 			\
		./src/cv/Rmakefile ./src/common/Rmakefile 		\
		./src/cal/Rmakefile installib				\
		./src/cv/mgflib/Makefile ./src/meta/lib4014/Makefile 	\
		./src/px/Rmakefile					\
		./src/px/tiff/contrib/acorn/Makefile 			\
		./src/px/tiff/contrib/addtiffo/Makefile  		\
		./src/px/tiff/contrib/iptcutil/Makefile

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PKGSRC_ARCH=	9
.elif ${OPSYS} == "FreeBSD"
PKGSRC_ARCH=	8
.endif

MAKE_ENV+=	MV="${MV}" RM="${RM}" CP="${CP}"			\
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" 			\
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"			\
		RANLIB="${RANLIB}" AR="${AR}"

do-configure:
.for patchee in ${PATCHEES}
	${SED} -e 's|@PREFIX@|${PREFIX}|g' 				\
		-e 's|@PKGSRC_ARCH@|${PKGSRC_ARCH}|g'			\
		-e 's|@WRKSRC@|${WRKSRC}|g'				\
		-e 's|@X11BASE@|${X11BASE}|g'				\
		-e 's|@MAKE@|${MAKE}|g'					\
		${WRKSRC}/${patchee} >	${WRKSRC}/${patchee}.tmp &&	\
	${MV} ${WRKSRC}/${patchee}.tmp ${WRKSRC}/${patchee}
.endfor

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} csh ./makeall install

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/radiance
	cd ${WRKSRC}/radiance && ${PAX} -rw . ${PREFIX}/radiance/
	${INSTALL_DATA_DIR} ${PREFIX}/radiance/obj
	cd ${WRKSRC}/obj && ${PAX} -rw . ${PREFIX}/radiance/obj/
	${INSTALL_DATA_DIR} ${PREFIX}/radiance/man
	cd ${WRKSRC}/doc/man && ${PAX} -rw . ${PREFIX}/radiance/man/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/radiance
	${INSTALL_DATA} ${WRKSRC}/doc/pdf/*.pdf ${PREFIX}/share/doc/radiance/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/radiance
	${INSTALL_DATA} ${WRKSRC}/doc/ray.html ${PREFIX}/share/doc/radiance/index.html

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
