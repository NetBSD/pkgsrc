# $NetBSD: Makefile,v 1.30 2012/10/03 12:55:15 asau Exp $

DISTNAME=	mmix-20060918
PKGREVISION=	1
CATEGORIES=	emulators devel lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~knuth/mmix.html
COMMENT=	Simulators for Knuth's MMIX RISC architecture

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=	tex-cweb-[0-9]*:../../print/tex-cweb
BUILD_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
BUILD_DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}
BUILD_TARGET=	all doc

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} abstime mmix mmixal 		\
		mmmix mmotype ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mmix
	cd ${WRKSRC} && ${INSTALL_DATA} README *.ps 			\
		${DESTDIR}${PREFIX}/share/doc/mmix
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/mmix
	cd ${WRKSRC} && ${INSTALL_DATA} *.mms *.mmix *.mmconfig 	\
		${DESTDIR}${PREFIX}/share/examples/mmix

.include "../../mk/bsd.pkg.mk"
