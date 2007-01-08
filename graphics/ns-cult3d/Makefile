# $NetBSD: Makefile,v 1.9 2007/01/08 01:50:41 rillig Exp $
#

DISTNAME=	Cult3D_NS4_5.2b1
PKGNAME=	ns-cult3d-5.2
PKGREVISION=	1
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

INSTALLATION_DIRS=	lib/netscape/plugins

post-extract:
	cd ${WRKSRC} && pax -r -f cult3d.tar
	chmod -R go-w ${WRKSRC}

do-install:
	cd ${WRKSRC} && pax -wr cult3d ${PREFIX}/lib/netscape/plugins
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ns-cult3d.txt

.include "../../mk/bsd.pkg.mk"
