# $NetBSD: Makefile,v 1.49 2011/11/30 11:59:39 wiz Exp $

DISTNAME=		audiofile-0.3.1
PKGNAME=		lib${DISTNAME}
PKGREVISION=		1
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

# g++ 4.1.3 complains about conversions from "double" to various integer types.
# As these look harmless and are accepted by g++ 4.2.1 (Mac OS X) and
# 4.5.3 (NetBSD 5.99.*) we just ignore them.
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.1.*)
BUILDLINK_TRANSFORM+=	rm:-Werror
.endif

post-install:
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
