# $NetBSD: Makefile,v 1.17 2000/12/13 16:35:23 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/27 08:31:48 fenner Exp
#

DISTNAME=		audiofile-0.1.11
PKGNAME=		lib${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.68k.org/pub/michael/ \
			${MASTER_SITE_GNOME:=stable/sources/audiofile/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

DOCDIR=			${PREFIX}/share/doc/libaudiofile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
