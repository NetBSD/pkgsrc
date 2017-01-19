# $NetBSD: Makefile,v 1.21 2017/01/19 18:52:09 agc Exp $

DISTNAME=	civctp-demo-10251999
PKGNAME=	civctp-demo-19991025
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.linuxgames.com/loki/demos/civctp/
MASTER_SITES+=	ftp://download.linuxlords.com/pub/demos/civctp/
MASTER_SITES+=	ftp://ftp.linux.tucows.com/pub/Loki/demos/civctp/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.lokigames.com/products/civctp/
COMMENT=	Civilization: Call to Power - graphical strategy (linux demo)

# Someone needs to look at alpha, powerpc and sparc compat_linux
EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

INSTALLATION_DIRS=	bin ${LIBDIR} ${SHAREDIR}

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/${WRKNAME}
BUILD_DIRS=	# empty

WRKNAME=	civctp_demo
DISTBINNAME=	civctp
BINNAME=	civctp-demo

DIST_SUBDIR=	lokigames
LIBDIR=		${PREFIX}/lib/lokigames/${BINNAME}
SHAREDIR=	${PREFIX}/share/doc/lokigames

BINTYPE.i386=		x86/glibc-2.1
BINTYPE.alpha=		alpha/glibc-2.1
BINTYPE.powerpc=	ppc/glibc-2.1
BINTYPE.sparc64=	sparc64/glibc-2.1
BINTYPE=		${BINTYPE.${EMUL_ARCH}}

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
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} && pax -rw appstr.txt civpaths.txt ctp_data \
		${DESTDIR}${LIBDIR}

.include "../../mk/bsd.pkg.mk"
