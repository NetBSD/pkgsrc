# $NetBSD: Makefile,v 1.39 2005/04/11 21:44:53 tv Exp $

DISTNAME=		audiofile-0.2.6
PKGNAME=		lib${DISTNAME}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.68k.org/~michael/audiofile/ \
			ftp://ftp.68k.org/pub/michael/ \
			${MASTER_SITE_GNOME:=sources/audiofile/0.2/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/
COMMENT=		Sound library for SGI audio file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	audiofile.pc.in

DOCDIR=			${PREFIX}/share/doc/libaudiofile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
