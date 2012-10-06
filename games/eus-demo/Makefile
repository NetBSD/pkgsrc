# $NetBSD: Makefile,v 1.19 2012/10/06 11:54:36 asau Exp $

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

USE_TOOLS+=	pax

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

INSTALLATION_DIRS=	bin ${LIBDIR} ${SHAREDIR}

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${LIBDIR}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

# The executable must be in the same directory as the data.
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh \
		${DESTDIR}${PREFIX}/bin/${BINNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINTYPE}/${DISTBINNAME} \
		${DESTDIR}${LIBDIR}/${BINNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} && pax -rw [Eai-p]* sounds ${DESTDIR}${LIBDIR}

.include "../../mk/bsd.pkg.mk"
