# $NetBSD: Makefile,v 1.2 2002/09/21 11:29:11 jlam Exp $
#

DISTNAME=	arcem0.50
PKGNAME=	arcem-0.50
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.arm.uk.linux.org/pub/linux/arcem/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		linux.rom.gz \
		HardImage1.gz

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	ftp://ftp.arm.uk.linux.org/pub/linux/arcem/Index
COMMENT=	Dave Gilbert's Acorn Archimedes emulator

WRKSRC=		${WRKDIR}/armul-arc

USE_BUILDLINK2=	# defined
USE_X11=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/arcem
	${INSTALL_DATA} ${WRKDIR}/linux.rom ${PREFIX}/share/arcem/ROM
	${INSTALL_DATA} ${WRKDIR}/HardImage1 ${PREFIX}/share/arcem/HardImage1
	${INSTALL_DATA} ${WRKSRC}/arch/dot.arcemrc \
				${PREFIX}/share/arcem/dot.arcemrc
	${INSTALL_DATA} ${WRKSRC}/hexcmos ${PREFIX}/share/arcem/hexcmos
	${INSTALL_DATA} ${WRKSRC}/hexcmos.2 ${PREFIX}/share/arcem/hexcmos.2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/arcem/README
	${INSTALL_DATA} ${WRKSRC}/README.OrElse \
				${PREFIX}/share/arcem/README.OrElse

.include "../../mk/bsd.pkg.mk"
