# $NetBSD: Makefile,v 1.23 2002/07/18 02:19:27 rh Exp $

DISTNAME=		audiofile-0.2.3
PKGNAME=		lib${DISTNAME}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.68k.org/pub/michael/ \
			${MASTER_SITE_GNOME:=stable/sources/audiofile/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/
COMMENT=		Sound library for SGI audio file

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

DOCDIR=			${PREFIX}/share/doc/libaudiofile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
