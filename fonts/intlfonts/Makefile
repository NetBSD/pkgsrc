# $NetBSD: Makefile,v 1.30 2012/10/03 18:28:24 asau Exp $

DISTNAME=	intlfonts-1.2.1
PKGREVISION=	5
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_GNU:=intlfonts/intlfonts-1.2.1-split/}
DISTFILES=	${FONT_SETS:=${EXTRACT_SUFX}} ${MISC_FILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Free X11 fonts (BDF format) for all characters that Emacs can handle

FONT_SETS=	Asian		\
		Chinese		\
		Ethiopic	\
		European	\
		Japanese	\
		Misc

USE_TOOLS+=	bdftopcf

# Use the X font set for Korean, as there isn't anything better
FONT_SETS+=	Korean.X

# These are extra files that not many folks will likely need or want
# They are all bigger than 24 dots -- you'll only want them if you
# want to display text in really big fonts.
#
EXTRA_FONTS=	Chinese.BIG	\
		European.BIG	\
		Japanese.BIG

# Type1/TrueType fonts for Latin1, Thai and Vietnamese
# XXX need "fonts.scale" for them
#
EXTRA_FONTS+=	Type1		\
		TrueType
CONFIGURE_ARGS+=	--with-type1 --with-truetype

MISC_FILES=	README.split

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.gz
EXTRACT_ONLY=	${FONT_SETS:=${EXTRACT_SUFX}}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-fontdir=${FONTS_DIR} \
		--enable-compress=gzip
INSTALL_MAKE_FLAGS+=	fontdir=${DESTDIR}${FONTS_DIR}

FONTS_DIR=	${PREFIX}/lib/X11/fonts/intlfonts

FONTS_DIRS.x11+=	${FONTS_DIR}
FONTS_DIRS.x11+=	${FONTS_DIR}/bdf
FONTS_DIRS.type1+=	${FONTS_DIR}/Type1
FONTS_DIRS.ttf+=	${FONTS_DIR}/TrueType
REQD_DIRS+=		${FONTS_DIR}
REQD_DIRS+=		${FONTS_DIR}/bdf
REQD_DIRS+=		${FONTS_DIR}/Type1
REQD_DIRS+=		${FONTS_DIR}/TrueType

.include "../../mk/bsd.prefs.mk"

.if !defined(NO_EXTRA_FONTS)
FONT_SETS+=	${EXTRA_FONTS}
PLIST_SRC=	PLIST PLIST.extrafonts
.endif

post-extract:
.for FILE in ${MISC_FILES}
	${CP} ${_DISTDIR}/${FILE} ${WRKSRC}
.endfor

.include "../../mk/bsd.pkg.mk"
