# $NetBSD: Makefile,v 1.22 2005/01/25 13:17:46 blymn Exp $
#

DISTNAME=	lwp-1.12
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/lwp/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Light Weight Process style threads

# ${WRKSRC}/src/process.ss needs pmap handling assembly for
# each arch. Mips has it, but it evidently needs more work.
#
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-sparc* \
			NetBSD-*-arm NetBSD-*-arm32 Linux-*-i386 NetBSD-*-x86_64

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
