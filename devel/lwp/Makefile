# $NetBSD: Makefile,v 1.11 2001/06/19 03:22:40 jlam Exp $
#

DISTNAME=	lwp-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/lwp/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Light Weight Process style threads

# ${WRKSRC}/src/process.ss needs pmap handling assembly for
# each arch. Mips has it, but it evidently needs more work.
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-sparc*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK_ONLY=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
