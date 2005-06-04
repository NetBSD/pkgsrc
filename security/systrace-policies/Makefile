# $NetBSD: Makefile,v 1.2 2005/06/04 00:35:28 kristerw Exp $

DISTNAME=	hairyeyeball-1.1
PKGREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	http://www.blafasel.org/~floh/he/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://blafasel.org/~floh/he/
COMMENT=	Systrace policy examples

WRKSRC=		${WRKDIR}/1.1

NO_BUILD=	YES

do-install:
	dir=${PREFIX}/share/examples/systrace-policies;			\
	${INSTALL_DATA_DIR} $$dir;					\
	cd ${WRKSRC} &&							\
		for f in *; do						\
			${INSTALL_DATA} $$f $$dir;			\
		done

.include "../../mk/bsd.pkg.mk"
