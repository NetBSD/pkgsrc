# $NetBSD: Makefile,v 1.16 2005/12/26 23:39:31 schmonz Exp $

DISTNAME=	mmix-20030622
PKGREVISION=	1
CATEGORIES=	emulators devel lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~knuth/mmix.html
COMMENT=	Simulators for Knuth's MMIX RISC architecture

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

BUILD_DEPENDS+= cweb-[0-9]*:../../devel/cweb

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
