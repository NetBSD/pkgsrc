# $NetBSD: Makefile,v 1.8 2001/02/16 14:38:41 wiz Exp $
#

DISTNAME=	lwp-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	fb@enteract.com
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
