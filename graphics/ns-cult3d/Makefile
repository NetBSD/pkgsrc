# $NetBSD: Makefile,v 1.2 2002/02/17 23:26:08 hubertf Exp $
#

DISTNAME=	cult3d-5.2-b1-linux-x86
PKGNAME=	ns-cult3d-5.2
CATEGORIES=	www graphics
DYNAMIC_MASTER_SITES= YES

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.cult3d.com/
COMMENT=	Netscape plugin for cult 3d files

ONLY_FOR_PLATFORM=      *-*-i386

NO_CONFIGURE=		yes
NO_BUILD=		yes
CHECK_SHLIBS=		no
CRYPTO=			yes

do-install:
	${MKDIR} ${PREFIX}/lib/netscape
	cd ${WRKSRC} ; ${ECHO} ${PREFIX}/lib/netscape | ./install.sh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ns-cult3d.txt

.include "../../mk/bsd.pkg.mk"
