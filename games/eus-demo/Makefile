# $NetBSD: Makefile,v 1.1.1.1 2000/10/16 12:24:35 abs Exp $
#

DISTNAME=	eus-demo
PKGNAME=	eus-demo-1.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.linuxgames.com/loki/demos/eus/ \
		ftp://download.linuxlords.com/pub/demos/eus/ \
		ftp://ftp.linux.tucows.com/pub/Loki/demos/eus/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.lokigames.com/products/eus/demo.php3

MIRROR_DISTFILE=no

NO_CONFIGURE=		yes

.if !make(fetch)
# Someone needs to look at alpha, powerpc and sparc compat_linux
ONLY_FOR_PLATFORM=*-*-i386
.endif

.if (${MACHINE_ARCH} == "i386")
BINTYPE=	x86/glibc-2.1
# DEPENDS+=	suse_base>=6.1:../../emulators/suse_base
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
WRKSRC=		${WRKDIR}/${WRKNAME}

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${LIBDIR}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

# The executable must be in the same directory as the data.
do-install:
	${MKDIR} ${LIBDIR}
	${MKDIR} ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${BINNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINTYPE}/${DISTBINNAME} ${LIBDIR}/${BINNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} ; ${PAX} -rw [Eai-p]* sounds ${LIBDIR}

.include "../../mk/bsd.pkg.mk"
