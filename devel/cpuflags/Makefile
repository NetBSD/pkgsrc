# $NetBSD: Makefile,v 1.62 2003/12/04 10:13:26 abs Exp $
#

DISTNAME=	cpuflags-0.59
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Determine compiler flags to best target current cpu

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-* SunOS-*-*

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cpuflags.${OPSYS} ${PREFIX}/bin/cpuflags
	${INSTALL_DATA} ${FILESDIR}/cpuflags.mk ${PREFIX}/share/mk/cpuflags.mk
	${INSTALL_DATA} ${FILESDIR}/optimize_gcc.mk ${PREFIX}/share/mk/optimize_gcc.mk
	${INSTALL_MAN} ${FILESDIR}/cpuflags.1 ${PREFIX}/man/man1/cpuflags.1

.include "../../mk/bsd.pkg.mk"
