# $NetBSD: Makefile,v 1.1.1.1 2001/06/07 09:59:28 abs Exp $
#

DISTNAME=		cpuflags-0.1
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		abs@netbsd.org
COMMENT=		Determine compiler flags to best target current cpu

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-*

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cpuflags.${OPSYS} ${PREFIX}/bin/cpuflags
	${INSTALL_MAN} ${FILESDIR}/cpuflags.1 ${PREFIX}/man/man1/cpuflags.1

.include "../../mk/bsd.pkg.mk"
