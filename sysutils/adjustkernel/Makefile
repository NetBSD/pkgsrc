# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:26 jmmv Exp $

DISTNAME=	adjustkernel-1.5
WRKSRC=		${WRKDIR}
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	mjl@netbsd.org
COMMENT=	Generate a kernel config

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
