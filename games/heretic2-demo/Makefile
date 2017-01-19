# $NetBSD: Makefile,v 1.25 2017/01/19 18:52:10 agc Exp $
#

DISTNAME=	heretic2-demo-x86
PKGNAME=	heretic2-demo-2.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.linuxgames.com/loki/demos/heretic2/
MASTER_SITES+=	ftp://download.linuxlords.com/pub/demos/heretic2/
MASTER_SITES+=	ftp://ftp.linux.tucows.com/pub/Loki/demos/heretic2/
EXTRACT_SUFX=	.run

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.lokigames.com/products/heretic2/
COMMENT=	Heretic2 - first person Quake 3D engine based (linux demo)

NO_CONFIGURE=	yes
EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' $$extract_file | \
								${GTAR} xzf -
USE_TOOLS+=	gtar pax

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
# DragonFly sed(1) adds trailing newline and it confuses gzip(1). Bsdtar,
# which doesn't use gzip but zlib, extracts the archive fine though.
TOOLS_PLATFORM.gtar=	/usr/bin/bsdtar
.endif

ONLY_FOR_PLATFORM=	*-*-i386
NOT_FOR_PLATFORM=	SunOS-*-*

DISTBINNAME=	heretic2_demo.x86
BINNAME=	heretic2-demo

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	lokigames
LIBDIR=		${PREFIX}/lib/lokigames/${BINNAME}
SHAREDIR=	${PREFIX}/share/doc/lokigames

INSTALLATION_DIRS=	bin ${LIBDIR} ${SHAREDIR}

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${LIBDIR}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

# The executable must be in the same directory as the data.
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh \
		${DESTDIR}${PREFIX}/bin/${BINNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTBINNAME} \
		${DESTDIR}${LIBDIR}/${BINNAME}
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${SHAREDIR}/${BINNAME}-QuickStart.txt
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} && pax -rw base gl_drivers icon.xpm ref_glx.so \
		${DESTDIR}${LIBDIR}

.include "../../mk/bsd.pkg.mk"
