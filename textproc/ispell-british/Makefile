# $NetBSD: Makefile,v 1.14 2005/12/05 20:51:03 rillig Exp $
#

DISTNAME=	ispell-3.3.02
PKGNAME=	ispell-${DICT_LANG}-3.3.02
CATEGORIES=	textproc
MASTER_SITES=	http://fmg-www.cs.ucla.edu/geoff/tars/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ficus-www.cs.ucla.edu/geoff/ispell.html
COMMENT=	British dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.3.02:../../textproc/ispell-base

BUILD_TARGET=	config.sh all-languages

DICT_LANG=	british

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
WORDS=		/usr/dict/words
.else
WORDS=		/usr/share/dict/words
.endif

INSTALLATION_DIRS=	lib

do-configure:
	cd ${WRKSRC};							\
	${SED} -e 's|/usr/local|${PREFIX}|g' <local.h.bsd >local.h;	\
	${ECHO} "#define LANGUAGES \"{${DICT_LANG},MASTERDICTS=${DICT_LANG}.xlg,HASHFILES=${DICT_LANG}xlg.hash,EXTRADICT=}\""  >>local.h; \
	${ECHO} '#define MASTERHASH "${DICT_LANG}xlg.hash"'  >> local.h ;	\
	${ECHO} "#undef WORDS"  >> local.h ;				\
	${ECHO} '#define WORDS   "${WORDS}"'  >> local.h

do-install:
	${CP} ${WRKSRC}/languages/${DICT_LANG}/${DICT_LANG}xlg.hash ${PREFIX}/lib
	cd ${PREFIX}/lib;						\
	${RM} -f ${DICT_LANG}.hash;					\
	${LN} ${DICT_LANG}xlg.hash ${DICT_LANG}.hash

.include "../../mk/bsd.pkg.mk"
