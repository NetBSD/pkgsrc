# $NetBSD: Makefile,v 1.3 2004/08/30 13:39:45 schmonz Exp $
#

DISTNAME=		safecat-1.12
CATEGORIES=		mail
MASTER_SITES=		http://pobox.com/~lbudney/linux/software/safecat/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://pobox.com/~lbudney/linux/software/safecat.html
COMMENT=		Write data safely to a maildir

USE_BUILDLINK3=		yes

ALL_TARGET=		it install instcheck
INSTALL_TARGET=		setup check

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-root

.include "../../mk/bsd.pkg.mk"
