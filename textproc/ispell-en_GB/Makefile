# $NetBSD: Makefile,v 1.13 2023/12/22 18:26:19 zafer Exp $

.include	"../../textproc/ispell/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-${DICT_LANG}-/1}
CATEGORIES=	textproc
MASTER_SITES=	https://www.cs.hmc.edu/~geoff/tars/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.hmc.edu/~geoff/ispell.html
COMMENT=	British dictionary for interactive spelling checker

CONFLICTS+=	ispell-british-[0-9]*
DEPENDS+=	ispell>=3.3.02:../../textproc/ispell

WRKSRC=	${WRKDIR}/${DISTNAME}/languages/english

DICT_LANG=	british

INSTALLATION_DIRS=	lib

OPSYSVARS+=	WORDS
WORDS.SunOS=	/usr/dict/words
WORDS.*=	/usr/share/dict/words

do-build:
	cd ${WRKSRC};						\
	${MAKE} CONFIG= MUNCHLIST=${PREFIX}/bin/munchlist VARIANTS=british \
	  EXTRADICT=${WORDS} SHELLDEBUG=+vx AFFIXES=english.aff english.xlg+; \
	${MAKE} CONFIG= BUILDHASH=${PREFIX}/bin/buildhash EXTRADICT=${WORDS} \
	  AFFIXES=english.aff SHELLDEBUG=+vx xlg+.hash

do-install:
	${INSTALL_DATA} ${WRKSRC}/english.aff ${DESTDIR}${PREFIX}/lib/${DICT_LANG}.aff
	${INSTALL_DATA} ${WRKSRC}/xlg+.hash ${DESTDIR}${PREFIX}/lib/${DICT_LANG}.hash

.include "../../mk/bsd.pkg.mk"
