# $NetBSD: Makefile,v 1.2 2004/04/18 05:13:35 snj Exp $
#

DISTNAME=		safecat-1.11
CATEGORIES=		mail
MASTER_SITES=		http://budney.homeunix.net:8080/users/budney/linux/software/safecat/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://budney.homeunix.net:8080/users/budney/linux/software/safecat.html
COMMENT=		Write data safely to a directory (using Bernstein's maildir algorithm)

USE_BUILDLINK3=		yes

ALL_TARGET=		#
INSTALL_TARGET=		setup check

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-root

.include "../../mk/bsd.pkg.mk"
