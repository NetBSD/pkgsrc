# $NetBSD: Makefile,v 1.1.1.1 1999/09/07 22:13:06 tron Exp $

DISTNAME=	intlfonts-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU:=intlfonts/}
DISTFILES=	${FONT_SETS:S/$/${EXTRACT_SUFX}/} ${MISC_FILES}

MAINTAINER=	packages@netbsd.org

FONT_SETS=	Asian		\
		Chinese		\
		Ethiopic	\
		European	\
		Japanese	\
		Misc

# These are extra files that not many folks will likely need or want
# They are all bigger than 24 dots -- you'll only want them if you
# want to display text in really big fonts.
#
EXTRA_FONTS=	Chinese-BIG	\
		European-BIG	\
		Japanese-BIG

MISC_FILES=	Makefile	\
		README		\
		README-split

DIST_SUBDIR=	intlfonts
EXTRACT_ONLY=	${FONT_SETS:S/$/${EXTRACT_SUFX}/}
MESSAGE_FILE=	${WRKSRC}/MESSAGE
USE_X11BASE=	yes
WRKSRC=		${WRKDIR}

post-extract:
.for FILE in ${MISC_FILES}
	${CP} ${_DISTDIR}/${FILE} ${WRKSRC}
.endfor

do-build:
	${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE >${MESSAGE_FILE}

do-install:
	(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${FONT_SETS})

.include "../../mk/bsd.pkg.mk"
