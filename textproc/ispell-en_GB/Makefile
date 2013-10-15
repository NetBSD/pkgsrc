# $NetBSD: Makefile,v 1.4 2013/10/15 15:54:25 roy Exp $
#

DISTNAME=	ispell-3.3.02
PKGNAME=	${DISTNAME:S/-/-${DICT_LANG}-/1}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://fmg-www.cs.ucla.edu/geoff/tars/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ficus-www.cs.ucla.edu/geoff/ispell.html
COMMENT=	British dictionary for interactive spelling checker

CONFLICTS+=	ispell-british-[0-9]*
DEPENDS+=	ispell>=3.3.02:../../textproc/ispell

BUILD_TARGET=	config.sh all-languages

DICT_LANG=	british

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}

INSTALLATION_DIRS=	lib
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
WORDS=		/usr/dict/words
.else
WORDS=		/usr/share/dict/words
.endif

do-configure:
	cd ${WRKSRC};							\
	${SED} -e 's|/usr/local|${PREFIX}|g' <local.h.bsd >local.h;	\
	${ECHO} "#define LANGUAGES \"{${DICT_LANG},MASTERDICTS=${DICT_LANG}.xlg,HASHFILES=${DICT_LANG}xlg.hash,EXTRADICT=}\""  >>local.h; \
	${ECHO} '#define MASTERHASH "${DICT_LANG}xlg.hash"'  >> local.h ;	\
	${ECHO} "#undef WORDS"  >> local.h ;				\
	${ECHO} '#define WORDS   "${WORDS}"'  >> local.h

do-install:
	${CP} ${WRKSRC}/languages/${DICT_LANG}/${DICT_LANG}xlg.hash ${DESTDIR}${PREFIX}/lib
	cd ${DESTDIR}${PREFIX}/lib;					\
	${RM} -f ${DICT_LANG}.hash;					\
	${LN} ${DICT_LANG}xlg.hash ${DICT_LANG}.hash

.include "../../mk/bsd.pkg.mk"
