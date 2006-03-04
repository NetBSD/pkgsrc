# $NetBSD: Makefile,v 1.3 2006/03/04 21:30:38 jlam Exp $

DISTNAME=	hairyeyeball-1.1
PKGREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	http://www.blafasel.org/~floh/he/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
