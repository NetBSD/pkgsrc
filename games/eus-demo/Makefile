# $NetBSD: Makefile,v 1.15 2007/07/29 05:19:25 jlam Exp $

DISTNAME=	eus-demo
PKGNAME=	eus-demo-1.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.linuxgames.com/loki/demos/eus/ \
		ftp://download.linuxlords.com/pub/demos/eus/ \
		ftp://ftp.linux.tucows.com/pub/Loki/demos/eus/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.lokigames.com/products/eus/
COMMENT=	Eric's Ultimate Solitaire (linux demo)

# Someone needs to look at alpha, powerpc and sparc compat_linux
EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

WRKSRC=		${WRKDIR}/${WRKNAME}
BUILD_DIRS=	# empty

WRKNAME=	eus_demo
DISTBINNAME=	EricsSolitaireDemo
BINNAME=	eus-demo

DIST_SUBDIR=	lokigames
LIBDIR=		${PREFIX}/lib/lokigames/${BINNAME}
SHAREDIR=	${PREFIX}/share/doc/lokigames

BINTYPE.i386=		x86/glibc-2.1
BINTYPE.alpha=		alpha/glibc-2.1
BINTYPE.powerpc=	ppc/glibc-2.1
BINTYPE.sparc64=	sparc64/glibc-2.1
BINTYPE=		${BINTYPE.${EMUL_ARCH}}

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${LIBDIR}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

# The executable must be in the same directory as the data.
do-install:
	${INSTALL_DATA_DIR} ${LIBDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${BINNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINTYPE}/${DISTBINNAME} ${LIBDIR}/${BINNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} && ${PAX} -rw [Eai-p]* sounds ${LIBDIR}

.include "../../mk/bsd.pkg.mk"
