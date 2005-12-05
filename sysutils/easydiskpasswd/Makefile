# $NetBSD: Makefile,v 1.6 2005/12/05 20:51:00 rillig Exp $

DISTNAME=	easydiskpasswd-1.0
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	Tool to unlock a password protected USB "EasyDisk"

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes

# we depend on SCIOCCOMMAND and the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*-*

do-extract:
	${CP} ${FILESDIR}/easydiskpasswd.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
