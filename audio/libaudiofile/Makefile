# $NetBSD: Makefile,v 1.30 2004/01/05 20:52:56 jlam Exp $

DISTNAME=		audiofile-0.2.4
PKGNAME=		lib${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://www.68k.org/~michael/audiofile/ \
			ftp://ftp.68k.org/pub/michael/ \
			${MASTER_SITE_GNOME:=sources/audiofile/0.2/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/
COMMENT=		Sound library for SGI audio file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/audiofile.pc.in

DOCDIR=			${PREFIX}/share/doc/libaudiofile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DOCDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-Wl,${RPATH_FLAG}/usr/ucblib -L/usr/ucblib
.endif

.include "../../mk/bsd.pkg.mk"
