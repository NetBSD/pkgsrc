# $NetBSD: Makefile,v 1.26 2002/10/30 03:09:26 rh Exp $

DISTNAME=		audiofile-0.2.3
PKGNAME=		lib${DISTNAME}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.68k.org/pub/michael/ \
			${MASTER_SITE_GNOME:=sources/audiofile/0.2/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/
COMMENT=		Sound library for SGI audio file

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/audiofile.pc.in

DOCDIR=			${PREFIX}/share/doc/libaudiofile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
