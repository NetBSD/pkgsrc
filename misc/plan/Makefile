# $NetBSD: Makefile,v 1.6 2000/07/11 09:55:51 agc Exp $
#

DISTNAME=	plan-1.8.2
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/plan/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html

USE_MOTIF=	YES

ALL_TARGET=	netbsd

pre-install:
	${MKDIR} ${X11PREFIX}/libexec/plan ${X11PREFIX}/share/plan \
		${X11PREFIX}/share/plan/holiday
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/holiday/holiday_* ${X11PREFIX}/share/plan/holiday
	for f in HISTORY README; do					\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$$f ${X11PREFIX}/share/plan; \
	done

.include "../../mk/bsd.pkg.mk"
