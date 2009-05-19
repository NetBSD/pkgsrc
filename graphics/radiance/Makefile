# $NetBSD: Makefile,v 1.24 2009/05/19 08:59:18 wiz Exp $
#

DISTNAME=	rad3R6P1
PKGNAME=	radiance-3.6.1
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.radiance-online.org/software/non-cvs/	\
		http://www.radiance-online.org/software/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}supp${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.radiance-online.org/
COMMENT=	Physically-based, image-generating, backward raytracer
LICENSE=	radiance-license

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/ray

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

PLIST_VARS+=	gl

.if ${OPSYS} == "NetBSD"
PKGSRC_ARCH=	9
.elif ${OPSYS} == "FreeBSD"
PKGSRC_ARCH=	8
.elif ${OPSYS} == "DragonFly"
PKGSRC_ARCH=	12
.elif ${OPSYS} == "Linux"
PKGSRC_ARCH=	6
.elif ${OPSYS} == "IRIX"
PKGSRC_ARCH=	3
PLIST.gl=	yes
.endif

MAKE_ENV+=	MV=${MV:Q} RM=${RM:Q} CP=${CP:Q}			\
		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q} 			\
		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}			\
		RANLIB=${RANLIB:Q} AR=${AR:Q}

DESTDIRPREFIX=	${DESTDIR}${PREFIX}

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
	${RM} ${WRKSRC}/lib/.gdb_history

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ${SH} ./makeall install
	${RM} -f ${WRKSRC}/radiance/bin/wish*

do-install:
	${INSTALL_DATA_DIR} ${DESTDIRPREFIX:Q}/radiance
	cd ${WRKSRC}/radiance && pax -rw -s '|.*/\.DS_Store||' . ${DESTDIRPREFIX:Q}/radiance/
	${INSTALL_DATA_DIR} ${DESTDIRPREFIX:Q}/radiance/obj
	cd ${WRKSRC}/obj && pax -rw -s '|.*/\.DS_Store||' . ${DESTDIRPREFIX:Q}/radiance/obj/
	${INSTALL_DATA_DIR} ${DESTDIRPREFIX:Q}/radiance/lib
	cd ${WRKSRC}/lib && pax -rw -s '|.*/\.DS_Store||' . ${DESTDIRPREFIX:Q}/radiance/lib/
	${INSTALL_DATA_DIR} ${DESTDIRPREFIX:Q}/radiance/man
	cd ${WRKSRC}/doc/man && pax -rw -s '|.*/\.DS_Store||' . ${DESTDIRPREFIX:Q}/radiance/man/
	${INSTALL_DATA_DIR} ${DESTDIRPREFIX:Q}/share/doc/radiance
	${INSTALL_DATA} ${WRKSRC}/doc/pdf/*.pdf \
		${DESTDIRPREFIX:Q}/share/doc/radiance/
	${INSTALL_DATA_DIR} ${DESTDIRPREFIX:Q}/share/doc/html/radiance
	${INSTALL_DATA} ${WRKSRC}/doc/ray.html \
		${DESTDIRPREFIX:Q}/share/doc/radiance/index.html

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
