# $NetBSD: Makefile,v 1.10 2002/07/24 02:32:17 hubertf Exp $

DISTNAME=	intlfonts-1.2
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_GNU:=intlfonts/intlfonts-1.2-split/}
DISTFILES=	${FONT_SETS:S/$/${EXTRACT_SUFX}/} ${MISC_FILES}

MAINTAINER=	packages@netbsd.org
COMMENT=	Free X11 fonts (BDF format) for all characters that Emacs can handle

FONT_SETS=	Asian		\
		Chinese		\
		Ethiopic	\
		European	\
		Japanese	\
		Misc

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
#EXTRA_FONTS+=	Type1		\
#		TrueType
#CONFIGURE_ARGS+=--with-type1 --with-truetype

MISC_FILES=	README.split

DIST_SUBDIR=	${PKGNAME}
EXTRACT_ONLY=	${FONT_SETS:S/$/${EXTRACT_SUFX}/}
USE_X11BASE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-fontdir=${PREFIX}/lib/X11/fonts/intlfonts \
		--enable-compress=gzip

.include "../../mk/bsd.prefs.mk"

.if !defined(NO_EXTRA_FONTS)
FONT_SETS+=	${EXTRA_FONTS}
PLIST_SRC=	${WRKDIR}/PLIST

# the order may look strange, but we need to make "@dirrm" the last item.
post-patch:
	${CAT} ${PKGDIR}/PLIST.extrafonts ${PKGDIR}/PLIST > ${PLIST_SRC}
.endif

post-extract:
.for FILE in ${MISC_FILES}
	${CP} ${_DISTDIR}/${FILE} ${WRKSRC}
.endfor

.include "../../mk/bsd.pkg.mk"
