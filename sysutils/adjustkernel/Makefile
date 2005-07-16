# $NetBSD: Makefile,v 1.11 2005/07/16 01:19:20 jlam Exp $

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

USE_TOOLS+=	perl:run
REPLACE_PERL=	adjustkernel

INSTALLATION_DIRS=	bin man/man1

do-extract:
	${CP} ${FILESDIR}/adjustkernel ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/adjustkernel ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/adjustkernel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
