# $NetBSD: Makefile,v 1.7 2002/08/23 20:35:28 kristerw Exp $

DISTNAME=	mmix
PKGNAME=	mmix-20020615
CATEGORIES=	emulators devel lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~knuth/mmix.html
COMMENT=	Simulators for Knuth's MMIX RISC architecture

BUILD_DEPENDS+= cweb-[0-9]*:../../devel/cweb

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}

ALL_TARGET=	all doc

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} abstime mmix mmixal 		\
		mmmix mmotype ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mmix
	cd ${WRKSRC} && ${INSTALL_DATA} README *.ps 			\
		${PREFIX}/share/doc/mmix
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mmix
	cd ${WRKSRC} && ${INSTALL_DATA} *.mms *.mmix *.mmconfig 	\
		${PREFIX}/share/examples/mmix

.include "../../mk/bsd.pkg.mk"
