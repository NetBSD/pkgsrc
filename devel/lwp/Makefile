# $NetBSD: Makefile,v 1.9 2001/04/27 19:00:36 phil Exp $
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

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

# Don't even to try to use pthreaded version.
pre-configure:
	${CP} ${FILESDIR}/config.cache ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
