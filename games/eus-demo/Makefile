# $NetBSD: Makefile,v 1.11 2003/09/19 05:18:37 dent Exp $

DISTNAME=	eus-demo
PKGNAME=	eus-demo-1.0
WRKSRC=		${WRKDIR}/${WRKNAME}
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.linuxgames.com/loki/demos/eus/ \
		ftp://download.linuxlords.com/pub/demos/eus/ \
		ftp://ftp.linux.tucows.com/pub/Loki/demos/eus/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.lokigames.com/products/eus/
COMMENT=	Eric's Ultimate Solitaire (linux demo)

NO_CONFIGURE=		yes

# Someone needs to look at alpha, powerpc and sparc compat_linux
ONLY_FOR_PLATFORM=*-*-i386

.if (${MACHINE_ARCH} == "i386")
BINTYPE=	x86/glibc-2.1

DEPENDS+=	suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11
.elif (${MACHINE_ARCH} == "alpha")
BINTYPE=	alpha/glibc-2.1
.elif (${MACHINE_ARCH} == "powerpc")
BINTYPE=	ppc/glibc-2.1
.elif (${MACHINE_ARCH} == "sparc64")
BINTYPE=	sparc64/glibc-2.1
.endif

WRKNAME=	eus_demo
DISTBINNAME=	EricsSolitaireDemo
BINNAME=	eus-demo

DIST_SUBDIR=	lokigames
LIBDIR=		${PREFIX}/lib/lokigames/${BINNAME}
SHAREDIR=	${PREFIX}/share/doc/lokigames

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

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
