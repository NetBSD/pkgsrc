# $NetBSD: Makefile,v 1.6 2004/01/20 12:26:15 agc Exp $

DISTNAME=	adjustkernel-1.5
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	mjl@NetBSD.org
COMMENT=	Generate a kernel config

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_BUILD=	yes
NO_MTREE=	yes

USE_PERL5=     YES

REPLACE_PERL=	adjustkernel

do-extract:
	${CP} ${FILESDIR}/adjustkernel ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/adjustkernel ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/adjustkernel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
