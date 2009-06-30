# $NetBSD: Makefile,v 1.28 2009/06/30 00:07:15 joerg Exp $

DISTNAME=	mmix-20060918
CATEGORIES=	emulators devel lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~knuth/mmix.html
COMMENT=	Simulators for Knuth's MMIX RISC architecture

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

TEX_DEPMETHOD=	build
TEX_ACCEPTED=	teTeX3

WRKSRC=		${WRKDIR}
BUILD_TARGET=	all doc

INSTALLATION_DIRS=	bin

.include "../../mk/tex.buildlink3.mk"

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
