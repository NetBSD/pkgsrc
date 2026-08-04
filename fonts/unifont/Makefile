# $NetBSD: Makefile,v 1.35 2026/08/04 20:28:55 wiz Exp $

DISTNAME=	unifont-15.0.03
CATEGORIES=	fonts
MASTER_SITES=	https://unifoundry.com/pub/unifont/${DISTNAME}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://unifoundry.com/unifont/
COMMENT=	GNU Unifont - glyphs for all printable code points in Unicode 9.0 BMP
LICENSE=	gnu-gpl-v2 # or later

USE_TOOLS+=	gmake perl:run

MAKE_FLAGS+=	USRDIR=${PREFIX}
MAKE_FLAGS+=	CONSOLEDEST=${DESTDIR}${PREFIX}/share/fonts/consolefonts
MAKE_FLAGS+=	FONTDEST=${DESTDIR}${PREFIX}/share/fonts
MAKE_FLAGS+=	PKGMANDIR=${PKGMANDIR}

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/truetype/unifont
FONTS_DIRS.otf+=	${PREFIX}/share/fonts/opentype/unifont
FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/misc

REPLACE_PERL+=	src/bdfimplode
REPLACE_PERL+=	src/hex2bdf
REPLACE_PERL+=	src/hex2sfd
REPLACE_PERL+=	src/hexbraille
REPLACE_PERL+=	src/hexdraw
REPLACE_PERL+=	src/hexkinya
REPLACE_PERL+=	src/hexmerge
REPLACE_PERL+=	src/johab2ucs2
REPLACE_PERL+=	src/unifont-viewer
REPLACE_PERL+=	src/unifontchojung
REPLACE_PERL+=	src/unifontksx
REPLACE_PERL+=	src/unihex2png
REPLACE_PERL+=	src/unihexrotate
REPLACE_PERL+=	src/unipng2hex

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
