# $NetBSD: Makefile,v 1.2 1998/12/30 10:02:33 frueauf Exp $
#

DISTNAME=	plan-1.7.2
WRKSRC=		${WRKDIR}/src
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.fu-berlin.de/pub/unix/graphics/plan/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html

USE_MOTIF=	YES

ALL_TARGET=	netbsd

pre-install:
	${MKDIR} ${X11BASE}/libexec/plan ${X11BASE}/share/plan \
		${X11BASE}/share/plan/holiday
	${INSTALL_DATA} ${WRKDIR}/holiday/holiday_* ${X11BASE}/share/plan/holiday
.for file in HISTORY README
	${INSTALL_DATA} ${WRKDIR}/${file} ${X11BASE}/share/plan
.endfor

.include "../../mk/bsd.pkg.mk"
