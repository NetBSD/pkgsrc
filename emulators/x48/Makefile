# $NetBSD: Makefile,v 1.13 2012/10/03 12:55:21 asau Exp $
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

INSTALLATION_DIRS+=	share/doc/x48/romdump

post-install:
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} CARDS.doc INSTALLING ROMDump.doc \
			${DESTDIR}${PREFIX}/share/doc/x48
	cd ${WRKSRC}/romdump && \
		${INSTALL_MAN} README ${DESTDIR}${PREFIX}/share/doc/x48/romdump && \
		${INSTALL_DATA} ROMDump ROMDump.s \
			${DESTDIR}${PREFIX}/share/doc/x48/romdump

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
