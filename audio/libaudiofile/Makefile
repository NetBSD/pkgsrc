# $NetBSD: Makefile,v 1.10 1999/10/25 23:26:46 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/27 08:31:48 fenner Exp
#

DISTNAME=	audiofile-0.1.9
PKGNAME=	libaudiofile-0.1.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://andromeda.68k.org./~michael/audiofile/

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libaudiofile
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* \
		${PREFIX}/share/doc/libaudiofile

.include "../../mk/bsd.pkg.mk"
