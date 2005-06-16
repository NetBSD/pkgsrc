# $NetBSD: Makefile,v 1.32 2005/06/16 06:57:41 jlam Exp $

DISTNAME=	sp3f4.kit
PKGNAME=	spice-3f5.1
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://bwrc.eecs.berkeley.edu/Classes/IcBook/SPICE/
COMMENT=	General-purpose circuit simulation program


WRKSRC=			${WRKDIR}
# GPL license used by GNU readline is not compatible
# with 4 clause BSD license used by spice.
#BUILDLINK_DEPENDS.readline=	readline>=4.0
#USE_GNU_READLINE=	uses rl_* interface

# documentation in ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps

#		These are included as patch-ae
#PATCH_SITES=	ftp://ilpsoft.eecs.berkeley.edu/pub/SPICE3F5/
#PATCHFILES=	grid.patch newcoms.patch spsmp.patch

INSTALLATION_DIRS=	bin man/man1 man/man3 man/man5

post-extract:
	${CP} ${FILESDIR}/NetBSD ${WRKSRC}/conf

do-configure:
	${RM} -f ${WRKSRC}/makefile
	cd ${WRKSRC}/conf; for file in NetBSD defaults; do		\
		${SED}	-e "s|@MAKE_PROGRAM@|${MAKE_PROGRAM}|g"		\
			-e "s|@CFLAGS@|${CFLAGS}|g"			\
			-e "s|@LDFLAGS@|${LDFLAGS}|g"			\
			-e 's|@X11BASE@|${X11BASE}|g'			\
			-e "s|@WRKSRC@|${WRKSRC}|g"			\
			-e 's|@PREFIX@|${PREFIX}|g'			\
			$${file} > $${file}.new;			\
		${MV} -f $${file}.new $${file};				\
	done

do-build:
	cd ${WRKSRC}; util/build NetBSD default

do-install:
	cd ${WRKSRC}; util/build NetBSD install
	${CHMOD} a+rx ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg		\
	  	${PREFIX}/bin/sconvert ${PREFIX}/bin/help		\
		${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	strip ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg			\
		${PREFIX}/bin/sconvert ${PREFIX}/bin/help		\
		${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	${CHMOD} -R a+rX ${PREFIX}/share/spice3
	${INSTALL_MAN} ${WRKSRC}/man/man5/mfbcap.5 ${PREFIX}/man/man5/mfbcap.5
	${INSTALL_MAN} ${WRKSRC}/man/man1/sconvert.1 ${PREFIX}/man/man1/sconvert.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/nutmeg.1 ${PREFIX}/man/man1/nutmeg.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/spice.1 ${PREFIX}/man/man1/spice.1
	${INSTALL_MAN} ${WRKSRC}/man/man3/mfb.3 ${PREFIX}/man/man3/mfb.3

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spice3
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${PREFIX}/share/examples/spice3

#.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
