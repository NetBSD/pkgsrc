# $NetBSD: Makefile,v 1.8 2006/07/27 15:16:44 jlam Exp $
#

DISTNAME=	Cult3D_NS4_5.2b1
PKGNAME=	ns-cult3d-5.2
CATEGORIES=	www graphics

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.cult3d.com/
COMMENT=	Netscape plugin for cult 3d files

NOT_FOR_PLATFORM=	Interix-*-*
ONLY_FOR_PLATFORM=      *-*-i386

WRKSRC=			${WRKDIR}/cult3d-5.2-b1-linux-x86
NO_CONFIGURE=		yes
NO_BUILD=		yes
CHECK_SHLIBS_SUPPORTED=	no
CRYPTO=			yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/lib/netscape
	cd ${WRKSRC} ; ${ECHO} ${PREFIX}/lib/netscape | ./install.sh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ns-cult3d.txt

.include "../../mk/bsd.pkg.mk"
