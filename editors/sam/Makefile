# $NetBSD: Makefile,v 1.16 2001/04/30 20:13:55 jtb Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/12 02:19:40 obrien Exp
#

DISTNAME=		sam
PKGNAME=		sam-4.3
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=		.msg.gz

MAINTAINER=		packages@netbsd.org
COMMENT=		Unix version of Rob Pike's editor for plan9

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

MANCOMPRESSED=		yes
USE_X11BASE=		yes
MAKE_ENV+=		X11PREFIX=${X11PREFIX}

DEPENDS+=		libXgFonts-1.0:../../fonts/Xg

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"

.if ${X11BASE} != "/usr/openwin"
OTHER_X_LIBS=	-lSM -lICE
.endif

do-build:
	for d in libXg libframe sam samterm; do				\
		(cd ${WRKSRC}/$$d; make -f Make.solaris 		\
				OTHER_X_LIBS="${OTHER_X_LIBS}");	\
	done
.endif # SunOS

.include "../../mk/bsd.pkg.mk"
