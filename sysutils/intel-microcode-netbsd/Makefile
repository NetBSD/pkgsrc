# $NetBSD: Makefile,v 1.5 2013/04/19 15:34:30 drochner Exp $
#

DISTNAME=	microcode-20130222
PKGNAME=	intel-microcode-netbsd-20130222
CATEGORIES=	sysutils
MASTER_SITES=	http://downloadmirror.intel.com/22508/eng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://downloadcenter.intel.com/Detail_Desc.aspx?DwnldID=22508
COMMENT=	Firmware updates for Intel x86 processors
#LICENSE=	# TODO: (see mk/license.mk)

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
