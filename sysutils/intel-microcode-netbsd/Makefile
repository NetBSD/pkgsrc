# $NetBSD: Makefile,v 1.2 2012/09/18 07:56:52 drochner Exp $
#

DISTNAME=	microcode-20120606
PKGNAME=	intel-microcode-netbsd-20120606
CATEGORIES=	sysutils
MASTER_SITES=	http://downloadmirror.intel.com/21385/eng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://downloadmirror.intel.com/21385/eng/
COMMENT=	Firmware updates for Intel x86 processors
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM+=	NetBSD-6.99.*-i386
ONLY_FOR_PLATFORM+=	NetBSD-6.99.*-x86_64

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c

FWDIR=	libdata/firmware/cpu_x86_intel1
INSTALLATION_DIRS+= ${FWDIR}

RCD_SCRIPTS+=	intel-microcode

post-extract:
	${CP} ${FILESDIR}/extract.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} extract.c -o extract

do-install:
	cd ${DESTDIR}${PREFIX}/${FWDIR} && \
		${WRKSRC}/extract ${WRKSRC}/microcode.dat

.include "../../mk/bsd.pkg.mk"
