# $NetBSD: Makefile,v 1.2 2002/06/18 16:20:21 wiz Exp $

DISTNAME=	${DISTNAME_${OPSYS}_${MACHINE_ARCH}}
PKGNAME=	dnetc-2.8015.469
CATEGORIES=	misc
MASTER_SITES=	http://http.distributed.net/pub/dcti/current-client/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.distributed.net/
COMMENT=	official distributed.net client

ONLY_FOR_PLATFORM=	Darwin-*-powerpc NetBSD-*-alpha NetBSD-*-arm32 \
			NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-sparc \
			SunOS-*-sparc
NO_BUILD=	YES

DISTNAME_Darwin_powerpc=	dnetc-darwin-ppc
DISTNAME_NetBSD_m68k=		dnetc-netbsd-68k
DISTNAME_NetBSD_alpha=		dnetc-netbsd-alpha
DISTNAME_NetBSD_arm32=		dnetc-netbsd-arm32
DISTNAME_NetBSD_i386=		dnetc-netbsd-i386-elf
DISTNAME_NetBSD_sparc=		dnetc-netbsd-sparc-elf
DISTNAME_SunOS_sparc=		dnetc-solaris-sparc

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; ${GTAR} -zxf ${DISTDIR}/${DISTFILES}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnetc/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/dnetc/
	${INSTALL_MAN} ${WRKSRC}/dnetc.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/dnetc ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
