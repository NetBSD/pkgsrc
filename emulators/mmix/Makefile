# $NetBSD: Makefile,v 1.12 2004/01/20 12:14:41 agc Exp $

DISTNAME=	mmix-20030622
CATEGORIES=	emulators devel lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~knuth/mmix.html
COMMENT=	Simulators for Knuth's MMIX RISC architecture

BUILD_DEPENDS+= cweb-[0-9]*:../../devel/cweb

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
