# $NetBSD: Makefile,v 1.11 1999/08/24 19:01:43 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/12 02:19:40 obrien Exp
#

DISTNAME=		sam
PKGNAME=		sam-4.3
CATEGORIES=		plan9
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=		.msg.gz

MAINTAINER=		packages@netbsd.org

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

MANCOMPRESSED=		yes
USE_X11=		yes

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
.endif

.include "../../mk/bsd.pkg.mk"
