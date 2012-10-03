# $NetBSD: Makefile,v 1.39 2012/10/03 11:43:42 asau Exp $

DISTNAME=		sam
PKGNAME=		sam-4.3
PKGREVISION=		3
CATEGORIES=		editors plan9
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=		.msg.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Unix version of Rob Pike's editor for plan9

DEPENDS+=		libXgFonts>=1.0nb1:../../fonts/Xg

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

MANCOMPRESSED=		yes
USE_X11BASE=		yes
MAKE_ENV+=		X11PREFIX=${X11PREFIX:Q}

INSTALLATION_DIRS=	bin include lib/X11/app-defaults \
	${PKGMANDIR}/man1 ${PKGMANDIR}/man3 ${PKGMANDIR}/man4 ${PKGMANDIR}/man6

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} X11PREFIX=${DESTDIR}${X11PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"

.if ${X11BASE} != "/usr/openwin"
OTHER_X_LIBS=	-lSM -lICE
.endif

do-build:
	for d in libXg libframe sam samterm; do				\
		(cd ${WRKSRC}/$$d; ${MAKE_PROGRAM} -f Make.solaris 	\
				OTHER_X_LIBS="${OTHER_X_LIBS}");	\
	done
.endif # SunOS

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
