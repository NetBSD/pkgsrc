# $NetBSD: Makefile,v 1.8 2015/01/15 08:46:59 msaitoh Exp $
#

DISTNAME=	microcode-20150107
PKGNAME=	intel-microcode-netbsd-20150107
CATEGORIES=	sysutils
MASTER_SITES=	http://downloadmirror.intel.com/24616/eng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://downloadcenter.intel.com/Detail_Desc.aspx?DwnldID=24616
COMMENT=	Firmware updates for Intel x86 processors
#LICENSE=	# TODO: (see mk/license.mk)

ONLY_FOR_PLATFORM+=	NetBSD-6.99.*-i386 \
			NetBSD-6.99.*-x86_64 \
			NetBSD-[7-9].*-i386 \
			NetBSD-[7-9].*-x86_64

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
