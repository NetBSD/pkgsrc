# $NetBSD: Makefile,v 1.12 2005/05/16 01:15:32 jlam Exp $

DISTNAME=	${DISTNAME_${OPSYS}_${MACHINE_ARCH}}
PKGNAME=	dnetc-2.${DISTVER_${OPSYS}_${MACHINE_ARCH}}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://http.distributed.net/pub/dcti/current-client/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.distributed.net/
COMMENT=	Official distributed.net client

ONLY_FOR_PLATFORM=	Darwin-*-powerpc NetBSD-*-alpha NetBSD-*-arm	\
			NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k	\
			NetBSD-*-mipsel NetBSD-*-powerpc NetBSD-*-sparc \
			NetBSD-*-sparc64 NetBSD-*-vax SunOS-*-sparc
NO_BUILD=	YES
USE_PKGINSTALL=	YES

PKGSRC_USE_TOOLS+=	gtar

DISTNAME_Darwin_powerpc=	dnetc-darwin-ppc
DISTNAME_NetBSD_m68k=		dnetc-netbsd-68k
DISTNAME_NetBSD_alpha=		dnetc-netbsd-alpha-elf
DISTNAME_NetBSD_arm=		dnetc-netbsd-arm32
DISTNAME_NetBSD_arm32=		dnetc-netbsd-arm32
DISTNAME_NetBSD_i386=		dnetc-netbsd-x86-elf
DISTNAME_NetBSD_mipsel=		dnetc-netbsd-mipsel
DISTNAME_NetBSD_powerpc=	dnetc-netbsd-ppc
DISTNAME_NetBSD_sparc=		dnetc-netbsd-sparc-elf
DISTNAME_NetBSD_sparc64=	dnetc-netbsd-sparc64-elf
DISTNAME_NetBSD_vax=		dnetc-netbsd-vax
DISTNAME_SunOS_sparc=		dnetc-solaris-sparc

DISTVER_Darwin_powerpc=		9005.484
DISTVER_NetBSD_m68k=		9005.483
DISTVER_NetBSD_alpha=		9003.481
DISTVER_NetBSD_arm=		9001.478
DISTVER_NetBSD_arm32=		${DISTVER_NetBSD_arm}
DISTVER_NetBSD_i386=		9007.486
DISTVER_NetBSD_mipsel=		9001.478
DISTVER_NetBSD_powerpc=		9005.484
DISTVER_NetBSD_sparc=		9001.478
DISTVER_NetBSD_sparc64=		9004.482
DISTVER_NetBSD_vax=		9003.480
DISTVER_SunOS_sparc=		9005.484

# wonkolicious macro expansion:
WRKSRC=${WRKDIR}/${DISTNAME:S/dnetc/dnetc${DISTVER_${OPSYS}_${MACHINE_ARCH}:E}/1}

RCD_SCRIPTS=	dnetc

.if ${MACHINE_ARCH} != "arm" && ${MACHINE_ARCH} != "arm32"
do-extract:
	@cd ${WRKDIR} && ${GTAR} -zxf ${DISTDIR}/${DISTFILES}
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
	${INSTALL_MAN} ${WRKSRC}/dnetc.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/dnetc ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
