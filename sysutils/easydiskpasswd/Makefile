# $NetBSD: Makefile,v 1.3 2003/07/17 22:53:32 grant Exp $

DISTNAME=	easydiskpasswd-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	tool to unlock a password protected USB "EasyDisk"

NO_CHECKSUM=	yes

# we depend on SCIOCCOMMAND and the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*

do-extract:
	${CP} ${FILESDIR}/easydiskpasswd.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
