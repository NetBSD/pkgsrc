# $NetBSD: Makefile,v 1.1.1.1 2003/08/15 09:50:03 zuntum Exp $
#

DISTNAME=		safecat-1.11
CATEGORIES=		mail
MASTER_SITES=		http://budney.homeunix.net:8080/users/budney/linux/software/safecat/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://budney.homeunix.net:8080/users/budney/linux/software/safecat.html
COMMENT=		Write data safely to a directory (using Bernstein's maildir algorithm)

USE_BUILDLINK2=		yes

ALL_TARGET=		#
INSTALL_TARGET=		setup check

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-root

.include "../../mk/bsd.pkg.mk"
