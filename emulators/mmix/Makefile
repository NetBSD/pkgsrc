# $NetBSD: Makefile,v 1.1.1.1 2001/04/12 21:52:13 jtb Exp $

DISTNAME=	mmix
PKGNAME=	mmix-20000918
CATEGORIES=	emulators devel lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	packages@netbsd.org
COMMENT=	Simulators for Knuth's MMIX RISC architecture

BUILD_DEPENDS+= cweb-*:../../devel/cweb

DIST_SUBDIR=	${PKGNAME}
NO_WRKSUBDIR=	yes

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
