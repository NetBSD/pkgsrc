# $NetBSD: Makefile,v 1.1.1.1 2005/03/24 17:11:45 agc Exp $

DISTNAME=	hairyeyeball-1.1
CATEGORIES=	security sysutils
MASTER_SITES=	http://www.blafasel.org/~floh/he/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://blafasel.org/~floh/he/
COMMENT=	Systrace policy examples

WRKSRC=		${WRKDIR}/1.1

NO_BUILD=	# defined

do-install:
	dir=${PREFIX}/share/examples/systrace-policies;			\
	${INSTALL_DATA_DIR} $$dir;					\
	cd ${WRKSRC} &&							\
		for f in *; do						\
			${INSTALL_DATA} $$f $$dir;			\
		done

.include "../../mk/bsd.pkg.mk"
