# $NetBSD: Makefile,v 1.21 2002/03/24 21:38:25 wiz Exp $
#

DISTNAME=		audiofile-0.2.3
PKGNAME=		lib${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.68k.org/pub/michael/ \
			${MASTER_SITE_GNOME:=stable/sources/audiofile/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/
COMMENT=		Sound library for SGI audio file

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

DOCDIR=			${PREFIX}/share/doc/libaudiofile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
