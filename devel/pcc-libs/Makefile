# $NetBSD: Makefile,v 1.7 2025/03/30 21:10:42 wiz Exp $

DISTNAME=	pcc-libs-1.1.0
CATEGORIES=	devel
MASTER_SITES=	#
EXTRACT_SUFX=	.tgz

HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Runtime libraries for the Portable C Compiler
LICENSE=	original-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-arm* NetBSD-*-i386 NetBSD-*-mips* \
			NetBSD-*-powerpc NetBSD-*-sparc64 NetBSD-*-vax \
			OpenBSD-*-i386 OpenBSD-*-vax \
			OpenBSD-*-powerpc OpenBSD-*-sparc64 \
			Darwin-*-i386 Darwin-*-powerpc \
			FreeBSD-*-i386 \
			Linux-*-i386 Linux-*-powerpc

# XXX For some reason building with bmake fails randomly.
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
