# $NetBSD: Makefile,v 1.53 2022/08/10 01:23:06 msaitoh Exp $

VERSION=	20220809
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

ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 069900
PKG_SKIP_REASON+=	"Loading microcode not supported"
.endif

FWDIR=	libdata/firmware/cpu_x86_intel1
INSTALLATION_DIRS+= ${FWDIR}

RCD_SCRIPTS+=	intel-microcode

post-extract:
	${CP} ${FILESDIR}/extract.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} extract.c -o extract

do-install:
	(if [ -f ${WRKSRC}/microcode.dat ]; then \
		cd ${DESTDIR}${PREFIX}/${FWDIR} && \
			${WRKSRC}/extract ${WRKSRC}/microcode.dat ; \
	else \
		cd ${DESTDIR}${PREFIX}/${FWDIR} && \
			${FIND} ${WRKSRC} -name '??-??-??' | xargs \
				${WRKSRC}/extract ; \
	fi)

.include "../../mk/bsd.pkg.mk"
