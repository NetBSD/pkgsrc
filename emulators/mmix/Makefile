# $NetBSD: Makefile,v 1.18 2006/01/19 15:50:05 tonio Exp $

DISTNAME=	mmix-20030622
PKGREVISION=	1
CATEGORIES=	emulators devel lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~knuth/mmix.html
COMMENT=	Simulators for Knuth's MMIX RISC architecture

BROKEN_IN=	pkgsrc-2005Q4

TEX_DEPMETHOD=	build
TEX_ACCEPTED=	teTeX1 teTeX2 teTeX3
.include "../../mk/tex.buildlink3.mk"
.if (${TEX_TYPE} == "teTeX1")
# mmix depends on cweb, so we need to also provide it when using teTeX1
BUILD_DEPENDS+= cweb-[0-9]*:../../devel/cweb
.endif

WRKSRC=		${WRKDIR}
BUILD_TARGET=	all doc

INSTALLATION_DIRS=	bin

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
