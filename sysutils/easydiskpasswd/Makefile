# $NetBSD: Makefile,v 1.1.1.1 2002/09/19 20:56:57 drochner Exp $

DISTNAME=	easydiskpasswd-1.0
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	drochner@netbsd.org
COMMENT=	tool to unlock a password protected USB "EasyDisk"

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes

# we depend on SCIOCCOMMAND and the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*

do-extract:
	${CP} ${FILESDIR}/easydiskpasswd.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
