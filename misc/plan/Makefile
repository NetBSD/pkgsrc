# $NetBSD: Makefile,v 1.4 1999/07/15 00:15:23 mjl Exp $
#

DISTNAME=	plan-1.8.2
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.fu-berlin.de/pub/unix/graphics/plan/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html

USE_MOTIF=	YES

ALL_TARGET=	netbsd

pre-install:
	${MKDIR} ${X11BASE}/libexec/plan ${X11BASE}/share/plan \
		${X11BASE}/share/plan/holiday
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/holiday/holiday_* ${X11BASE}/share/plan/holiday
.for file in HISTORY README
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${file} ${X11BASE}/share/plan
.endfor

.include "../../mk/bsd.pkg.mk"
