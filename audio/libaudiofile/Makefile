# $NetBSD: Makefile,v 1.14 2000/06/09 06:41:48 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/27 08:31:48 fenner Exp
#

DISTNAME=		audiofile-0.1.9
PKGNAME=		libaudiofile-0.1.9
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/audiofile/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libaudiofile
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* \
		${PREFIX}/share/doc/libaudiofile

.include "../../mk/bsd.pkg.mk"
