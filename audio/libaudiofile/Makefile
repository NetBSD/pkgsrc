# $NetBSD: Makefile,v 1.42.10.1 2009/01/22 20:21:28 tron Exp $

DISTNAME=		audiofile-0.2.6
PKGNAME=		lib${DISTNAME}
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.68k.org/~michael/audiofile/ \
			${MASTER_SITE_GNOME:=sources/audiofile/0.2/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/
COMMENT=		Sound library for SGI audio file

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	audiofile.pc.in

DOCDIR=			${PREFIX}/share/doc/libaudiofile

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
