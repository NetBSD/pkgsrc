# $NetBSD: Makefile,v 1.48 2019/06/08 11:04:30 rillig Exp $

DISTNAME=	sp3f4.kit
PKGNAME=	spice-3f5.1
PKGREVISION=	6
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://bwrc.eecs.berkeley.edu/Classes/IcBook/SPICE/
COMMENT=	General-purpose circuit simulation program

WRKSRC=			${WRKDIR}
# GPL license used by GNU readline is not compatible
# with 4 clause BSD license used by spice.
#BUILDLINK_API_DEPENDS.readline=	readline>=4.0
#USE_GNU_READLINE=	uses rl_* interface

# documentation in ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps

#		These are included as patch-ae
#PATCH_SITES=	ftp://ilpsoft.eecs.berkeley.edu/pub/SPICE3F5/
#PATCHFILES=	grid.patch newcoms.patch spsmp.patch

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man3 ${PKGMANDIR}/man5

MAKE_ENV+=	WRKSRC=${WRKSRC}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
CFLAGS+=	-Dlinux
.elif ${OPSYS} != "SunOS"
CFLAGS+=	-Dbsd
.endif

post-extract:
	${CP} ${FILESDIR}/NetBSD ${WRKSRC}/conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	conf/NetBSD conf/defaults
SUBST_VARS.conf=	MAKE_PROGRAM CFLAGS LDFLAGS WRKSRC PREFIX X11BASE

do-configure:
	rm -f ${WRKSRC}/makefile

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} util/build NetBSD default

INSTALLATION_DIRS+=	share/examples/spice3

do-install:
	cd ${WRKSRC} && env ${MAKE_ENV} ${INSTALL_ENV} util/build NetBSD install
	${CHMOD} a+rx ${DESTDIR}${PREFIX}/bin/spice3	\
		${DESTDIR}${PREFIX}/bin/nutmeg		\
	  	${DESTDIR}${PREFIX}/bin/sconvert	\
		${DESTDIR}${PREFIX}/bin/help		\
		${DESTDIR}${PREFIX}/bin/proc2mod	\
		${DESTDIR}${PREFIX}/bin/multidec
	strip ${DESTDIR}${PREFIX}/bin/spice3		\
		${DESTDIR}${PREFIX}/bin/nutmeg		\
		${DESTDIR}${PREFIX}/bin/sconvert	\
		${DESTDIR}${PREFIX}/bin/help		\
		${DESTDIR}${PREFIX}/bin/proc2mod	\
		${DESTDIR}${PREFIX}/bin/multidec
	${CHMOD} -R a+rX ${DESTDIR}${PREFIX}/share/spice3
	${INSTALL_MAN} ${WRKSRC}/man/man5/mfbcap.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/mfbcap.5
	${INSTALL_MAN} ${WRKSRC}/man/man1/sconvert.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sconvert.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/nutmeg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nutmeg.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/spice.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/spice.1
	${INSTALL_MAN} ${WRKSRC}/man/man3/mfb.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/mfb.3

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${DESTDIR}${PREFIX}/share/examples/spice3

#.include "../../devel/readline/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
