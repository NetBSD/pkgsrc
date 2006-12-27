# $NetBSD: Makefile,v 1.11 2006/12/27 13:37:36 joerg Exp $
#

DISTNAME=	x48_041
PKGNAME=	x48-0.4.1
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://home.earthlink.net/~rmmlgetz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.earthlink.net/~rmmlgetz/
COMMENT=	HP48 emulator

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_IMAKE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/x48
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/x48/romdump
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} CARDS.doc INSTALLING ROMDump.doc \
			${PREFIX}/share/doc/x48
	cd ${WRKSRC}/romdump && \
		${INSTALL_MAN} README ${PREFIX}/share/doc/x48/romdump && \
		${INSTALL_DATA} ROMDump ROMDump.s \
			${PREFIX}/share/doc/x48/romdump

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
