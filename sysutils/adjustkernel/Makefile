# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:33 jlam Exp $

DISTNAME=	adjustkernel-1.7
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	mjl@NetBSD.org
COMMENT=	Generate a NetBSD kernel config

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_BUILD=	yes
NO_MTREE=	yes

USE_PERL5=     YES

REPLACE_PERL=	adjustkernel

INSTALLATION_DIRS=	bin man/man1

do-extract:
	${CP} ${FILESDIR}/adjustkernel ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/adjustkernel ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/adjustkernel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
