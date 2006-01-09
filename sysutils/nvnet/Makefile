# $NetBSD: Makefile,v 1.1.1.1 2006/01/09 12:44:15 manu Exp $
#

PKGNAME=		nvnet-20050620nb1
DISTNAME=		nvnet-netbsd-src-20050620.tgz
DISTNAME+=		NFORCE-Linux-x86-1.0-0310-pkg1.run
CATEGORIES=		sysutils
MASTER_SITES+=		http://www.morgart.com/NetBSD/nVidia/nvnet/
MASTER_SITES+=		http://download.nvidia.com/XFree86/nforce/1.0-0310/

EXTRACT_SUFX=

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://www.morgart.com/NetBSD/nVidia/nvnet/
COMMENT=		Driver for nVidia ethernet

LICENSE=                nvidia-license

RESTRICTED=             "nVidia Licensed Software: http://www.nvidia.com/object/nv_swlicense.html"
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}


WRKSRC=		${WRKDIR}/nvnet

ONLY_FOR_PLATFORM=	NetBSD-*-i386

INSTALLATION_DIRS=	lkm man/man4

MESSAGE_SUBST+=  PREFIX=${PREFIX:Q}

do-extract:
	${TAR} -xzf ${DISTDIR}/nvnet-netbsd-src-20050620.tgz -C ${WRKDIR}
	cd ${WRKDIR} && ${SH} ${DISTDIR}/NFORCE-Linux-x86-1.0-0310-pkg1.run -x

do-install:
	${INSTALL} -c -m 755 ${WRKSRC}/module/nv.o ${PREFIX}/lkm/nv.o
	${INSTALL_MAN} ${WRKSRC}/man/nv.4 ${PREFIX}/man/man4/nv.4

.include "../../mk/bsd.pkg.mk"
