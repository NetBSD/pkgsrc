# $NetBSD: Makefile,v 1.12.2.2 2002/07/01 17:44:57 jlam Exp $
#

DISTNAME=	lwp-1.9
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
			NetBSD-*-arm32

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
