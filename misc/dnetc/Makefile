# $NetBSD: Makefile,v 1.18 2006/09/06 20:38:57 wiz Exp $

DISTNAME=	${DISTNAME_${OPSYS}_${MACHINE_ARCH}}
PKGNAME=	dnetc-2.${DISTVER_${OPSYS}_${MACHINE_ARCH}}
CATEGORIES=	misc
MASTER_SITES=	http://http.distributed.net/pub/dcti/current-client/ \
		ftp://ftp.distributed.net/pub/dcti/current-client/

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://www.distributed.net/
COMMENT=	Official distributed.net client

ONLY_FOR_PLATFORM=	Darwin-*-powerpc NetBSD-*-alpha NetBSD-*-arm	\
			NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k	\
			NetBSD-*-mipsel NetBSD-*-powerpc NetBSD-*-sparc \
			NetBSD-*-sparc64 NetBSD-*-vax SunOS-*-sparc	\
			SunOS-*-sparc64
NO_BUILD=	YES

USE_TOOLS+=	gtar

DISTNAME_Darwin_powerpc=	dnetc-macosx-ppc
DISTNAME_NetBSD_m68k=		dnetc-netbsd-m68k-elf
DISTNAME_NetBSD_alpha=		dnetc-netbsd-alpha-elf
DISTNAME_NetBSD_arm=		dnetc-netbsd-arm32
DISTNAME_NetBSD_arm32=		dnetc-netbsd-arm32
DISTNAME_NetBSD_i386=		dnetc-netbsd-x86-elf
DISTNAME_NetBSD_mipsel=		dnetc-netbsd-mipsel-elf
DISTNAME_NetBSD_powerpc=	dnetc-netbsd-ppc
DISTNAME_NetBSD_sparc=		dnetc-netbsd-sparc-elf
DISTNAME_NetBSD_sparc64=	dnetc-netbsd-sparc64-elf
DISTNAME_NetBSD_vax=		dnetc-netbsd-vax
DISTNAME_SunOS_sparc=		dnetc-solaris26-sparc32
DISTNAME_SunOS_sparc64=		dnetc-solaris7-sparc64

DISTVER_Darwin_powerpc=		9012.497
DISTVER_NetBSD_m68k=		9005.483
DISTVER_NetBSD_alpha=		9003.481
DISTVER_NetBSD_arm=		9001.478
DISTVER_NetBSD_arm32=		${DISTVER_NetBSD_arm}
DISTVER_NetBSD_i386=		9008.492
DISTVER_NetBSD_mipsel=		9006.485
DISTVER_NetBSD_powerpc=		9008.492
DISTVER_NetBSD_sparc=		9001.478
DISTVER_NetBSD_sparc64=		9004.482
DISTVER_NetBSD_vax=		9008.492
DISTVER_SunOS_sparc=		9009.494
DISTVER_SunOS_sparc64=		9009.494

# wonkolicious macro expansion:
WRKSRC=${WRKDIR}/${DISTNAME:S/dnetc/dnetc${DISTVER_${OPSYS}_${MACHINE_ARCH}:E}/1}

RCD_SCRIPTS=	dnetc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.if ${MACHINE_ARCH} != "arm" && ${MACHINE_ARCH} != "arm32"
do-extract:
	cd ${WRKDIR} && ${GTAR} -zxf ${DISTDIR}/${DISTFILES:Q}
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnetc/
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32" \
    || ${MACHINE_ARCH} == "sparc"
	${INSTALL_DATA} ${WRKSRC}/readme.* ${PREFIX}/share/doc/dnetc/
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/dnetc/
.else
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/dnetc/
.endif
	${INSTALL_MAN} ${WRKSRC}/dnetc.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/dnetc ${PREFIX}/bin/

.if defined(PKG_DEVELOPER) && defined(ALL_DISTFILES)
all-distfiles:
.	undef DISTFILES
.	for platform in ${ONLY_FOR_PLATFORM}
DISTFILES+=	${DISTNAME_${platform:C/-\*-/_/}}${EXTRACT_SUFX}
.	endfor
.endif

.include "../../mk/bsd.pkg.mk"
