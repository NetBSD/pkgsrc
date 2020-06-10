# $NetBSD: Makefile,v 1.39 2020/06/10 02:29:44 msaitoh Exp $

VERSION=	20200609
DISTNAME=	microcode-${VERSION}
PKGNAME=	intel-microcode-netbsd-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_PROJECT=	Intel-Linux-Processor-Microcode-Data-Files
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/Intel-Linux-Processor-Microcode-Data-Files/
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
