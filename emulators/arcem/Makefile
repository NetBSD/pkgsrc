# $NetBSD: Makefile,v 1.14 2006/07/27 18:48:02 jlam Exp $
#

DISTNAME=	arcem-1.00-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arcem/}

EXTRACT_SUFX=	.tgz

LINUX_FILES=	\
		linux.rom.gz \
		HardImage1.gz

.for f in ${LINUX_FILES}
SITES.${f}+=	\
		ftp://ftp.arm.uk.linux.org/pub/linux/arcem/
.endfor

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LINUX_FILES}

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://arcem.sourceforge.net/
COMMENT=	Dave Gilbert's Acorn Archimedes emulator

WRKSRC=		${WRKDIR}/arcem
USE_TOOLS+=	gmake

MAKE_ENV+=	SYSTEM=X

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/arcem
	${INSTALL_DATA} ${WRKDIR}/linux.rom ${PREFIX}/share/arcem/ROM
	${INSTALL_DATA} ${WRKDIR}/HardImage1 ${PREFIX}/share/arcem/HardImage1
	${INSTALL_DATA} ${FILESDIR}/dot.arcemrc \
		${PREFIX}/share/arcem/dot.arcemrc
	${INSTALL_DATA} ${WRKSRC}/hexcmos ${PREFIX}/share/arcem/hexcmos

.include "../../mk/bsd.pkg.mk"
