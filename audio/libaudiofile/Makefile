# $NetBSD: Makefile,v 1.47 2011/11/30 08:29:36 tron Exp $

DISTNAME=		audiofile-0.3.1
PKGNAME=		lib${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://www.68k.org/~michael/audiofile/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/
COMMENT=		Sound library for SGI audio file
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	audiofile.pc.in

DOCDIR=			${PREFIX}/share/doc/libaudiofile

INSTALLATION_DIRS=	${DOCDIR}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.1.*)
BUILDLINK_TRANSFORM+=	rm:-Werror
.endif

post-install:
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
