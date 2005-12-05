# $NetBSD: Makefile,v 1.30 2005/12/05 20:50:10 rillig Exp $

DISTNAME=		sam
PKGNAME=		sam-4.3
PKGREVISION=		2
CATEGORIES=		editors plan9
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=		.msg.gz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Unix version of Rob Pike's editor for plan9

DEPENDS+=		libXgFonts-1.0:../../fonts/Xg

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

MANCOMPRESSED=		yes
USE_X11BASE=		yes
MAKE_ENV+=		X11PREFIX=${X11PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"

.if ${X11BASE} != "/usr/openwin"
OTHER_X_LIBS=	-lSM -lICE
.endif

.include "../../mk/x11.buildlink3.mk"

do-build:
	for d in libXg libframe sam samterm; do				\
		(cd ${WRKSRC}/$$d; ${MAKE_PROGRAM} -f Make.solaris 	\
				OTHER_X_LIBS="${OTHER_X_LIBS}");	\
	done
.endif # SunOS

.include "../../mk/bsd.pkg.mk"
