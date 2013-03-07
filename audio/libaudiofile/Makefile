# $NetBSD: Makefile,v 1.59 2013/03/07 17:03:11 adam Exp $

DISTNAME=	audiofile-0.3.6
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://www.68k.org/~michael/audiofile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://andromeda.68k.org/~michael/audiofile/
COMMENT=	Sound library for SGI audio file
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	audiofile.pc.in

DOCDIR=			${PREFIX}/share/doc/libaudiofile

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	cd ${WRKSRC}/docs && ${INSTALL_DATA} af* sf* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
