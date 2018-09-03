# $NetBSD: Makefile,v 1.27 2018/09/03 11:00:36 leot Exp $

DISTNAME=	microcode-20180807a
PKGNAME=	intel-microcode-netbsd-20180807a
CATEGORIES=	sysutils
MASTER_SITES=	https://downloadmirror.intel.com/28087/eng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://downloadcenter.intel.com/download/28087/Linux-Processor-Microcode-Data-File
COMMENT=	Firmware updates for Intel x86 processors
LICENSE=	intel-microcode-license

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
	@(if [ -f ${WRKSRC}/microcode.dat ]; then \
		cd ${DESTDIR}${PREFIX}/${FWDIR} && \
			${WRKSRC}/extract ${WRKSRC}/microcode.dat ; \
	else \
		cd ${DESTDIR}${PREFIX}/${FWDIR} && \
			${FIND} ${WRKSRC} -name '??-??-??' | xargs \
				${WRKSRC}/extract ; \
	fi)

.include "../../mk/bsd.pkg.mk"
