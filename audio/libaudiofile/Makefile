# $NetBSD: Makefile,v 1.11 2000/01/02 18:02:40 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/27 08:31:48 fenner Exp
#

DISTNAME=	audiofile-0.1.9
PKGNAME=	libaudiofile-0.1.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/releases/gnome-1.0.53/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://andromeda.68k.org./~michael/audiofile/

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libaudiofile
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* \
		${PREFIX}/share/doc/libaudiofile

.include "../../mk/bsd.pkg.mk"
