# $NetBSD: Makefile,v 1.9 2003/10/03 15:57:08 kristerw Exp $

DISTNAME=	${DISTNAME_${OPSYS}_${MACHINE_ARCH}}
PKGNAME=	dnetc-2.8018.472
CATEGORIES=	misc
MASTER_SITES=	http://http.distributed.net/pub/dcti/current-client/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.distributed.net/
COMMENT=	Official distributed.net client

ONLY_FOR_PLATFORM=	Darwin-*-powerpc NetBSD-*-alpha NetBSD-*-arm	\
			NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k	\
			NetBSD-*-sparc SunOS-*-sparc
NO_BUILD=	YES
USE_PKGINSTALL=	YES

DISTNAME_Darwin_powerpc=	dnetc-darwin-ppc
DISTNAME_NetBSD_m68k=		dnetc-netbsd-68k
DISTNAME_NetBSD_alpha=		dnetc-netbsd-alpha-elf
DISTNAME_NetBSD_arm=		dnetc-netbsd-arm32
DISTNAME_NetBSD_arm32=		dnetc-netbsd-arm32
DISTNAME_NetBSD_i386=		dnetc-netbsd-i386-elf
DISTNAME_NetBSD_sparc=		dnetc-netbsd-sparc-elf
DISTNAME_SunOS_sparc=		dnetc-solaris-sparc

RCD_SCRIPTS=	dnetc

.if ${MACHINE_ARCH} != "arm" && ${MACHINE_ARCH} != "arm32"
do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; ${GTAR} -zxf ${DISTDIR}/${DISTFILES}
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnetc/
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
	${INSTALL_DATA} ${WRKSRC}/readme.* ${PREFIX}/share/doc/dnetc/
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/dnetc/
.else
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/dnetc/
.endif
	${INSTALL_MAN} ${WRKSRC}/dnetc.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/dnetc ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
