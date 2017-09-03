# $NetBSD: Makefile,v 1.17 2017/09/03 08:36:55 wiz Exp $
#

DISTNAME=	Cult3D_NS4_5.2b1
PKGNAME=	ns-cult3d-5.2
PKGREVISION=	1
CATEGORIES=	www graphics

MAINTAINER=	abs@NetBSD.org
#HOMEPAGE=	http://www.cult3d.com/
COMMENT=	Netscape plugin for cult 3d files

# Linux binary plugin
NOT_FOR_PLATFORM+=	Interix-*-*
ONLY_FOR_PLATFORM=	*-*-i386

# Politically incorrect on Dragonfly:
# http://leaf.dragonflybsd.org/mailarchive/users/2012-05/msg00066.html
NOT_FOR_PLATFORM+=	DragonFly-*-*

WRKSRC=			${WRKDIR}/cult3d-5.2-b1-linux-x86
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_TOOLS+=		pax
CHECK_SHLIBS_SUPPORTED=	no
CRYPTO=			yes

INSTALLATION_DIRS=	lib/netscape/plugins share/doc

post-extract:
	cd ${WRKSRC} && pax -r -f cult3d.tar
	chmod -R go-w ${WRKSRC}

do-install:
	cd ${WRKSRC} && pax -wr cult3d \
		${DESTDIR}${PREFIX}/lib/netscape/plugins
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/ns-cult3d.txt

.include "../../mk/bsd.pkg.mk"
