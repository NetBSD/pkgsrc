# $NetBSD: Makefile,v 1.9 2004/07/29 21:47:09 wiz Exp $
#

DISTNAME=	mousetar-20021217
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/mouse/tar/
DISTFILES=	tar.c tar.man

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	none
COMMENT=	der Mouse's version of tar program

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-[2-9].*-*} != ""
CPPFLAGS+=	-DTAR_INODE_INTERNAL
.endif

do-extract:
	for f in ${DISTFILES}; do					\
		${CP} ${DISTDIR}/$$f ${WRKDIR};				\
	done

do-build:
	cd ${WRKSRC}; ${CC} ${CPPFLAGS} ${CFLAGS} tar.c -o mousetar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mousetar ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tar.man ${PREFIX}/man/man1/mousetar.1

.include "../../mk/bsd.pkg.mk"
