# $NetBSD: Makefile,v 1.17 2001/05/01 09:16:24 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/12 02:19:40 obrien Exp
#

DISTNAME=		sam
PKGNAME=		sam-4.3nb1
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=		.msg.gz

MAINTAINER=		packages@netbsd.org
COMMENT=		Unix version of Rob Pike's editor for plan9

DEPENDS+=		libXgFonts-1.0:../../fonts/Xg

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

MANCOMPRESSED=		yes
USE_X11BASE=		yes
MAKE_ENV+=		X11PREFIX=${X11PREFIX}

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
