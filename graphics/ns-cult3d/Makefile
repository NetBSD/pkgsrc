# $NetBSD: Makefile,v 1.4 2004/01/24 00:38:23 kristerw Exp $
#

DISTNAME=	Cult3D_NS4_5.2b1
PKGNAME=	ns-cult3d-5.2
CATEGORIES=	www graphics
DYNAMIC_MASTER_SITES= YES

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.cult3d.com/
COMMENT=	Netscape plugin for cult 3d files

ONLY_FOR_PLATFORM=      *-*-i386

WRKSRC=			${WRKDIR}/cult3d-5.2-b1-linux-x86
NO_CONFIGURE=		yes
NO_BUILD=		yes
CHECK_SHLIBS=		no
CRYPTO=			yes

do-install:
	${MKDIR} ${PREFIX}/lib/netscape
	cd ${WRKSRC} ; ${ECHO} ${PREFIX}/lib/netscape | ./install.sh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ns-cult3d.txt

.include "../../mk/bsd.pkg.mk"
