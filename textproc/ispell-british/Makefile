# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 12:12:21 agc Exp $
#

DISTNAME=	ispell-3.1.20
PKGNAME=	ispell-${DICT_LANG}-3.1.20
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	British dictionary for interactive spelling checker

DEPENDS+=	ispell-base-3.1.20:../../textproc/ispell-base
CONFLICTS+=	ispell-[0-9]*

WRKSRC=		${WRKDIR}/ispell-3.1

ALL_TARGET=	config.sh all-languages

DICT_LANG=	british

do-configure:
	cd ${WRKSRC};							\
	${SED} -e 's|/usr/local|${PREFIX}|g' <local.h.samp >local.h;	\
	${ECHO} "#undef NO8BIT" >> local.h ;				\
	${ECHO} "#define LANGUAGES \"{${DICT_LANG},MASTERDICTS=${DICT_LANG}.xlg,HASHFILES=${DICT_LANG}xlg.hash,EXTRADICT=}\""  >>local.h; \
	${ECHO} '#define MASTERHASH "${DICT_LANG}xlg.hash"'  >> local.h ;	\
	${ECHO} "#undef WORDS"  >> local.h ;				\
	${ECHO} '#define WORDS   "/usr/share/dict/words"'  >> local.h ;	\
	${ECHO} '#undef ELISPDIR'  >> local.h;				\
	${ECHO} "#define ELISPDIR \"${PREFIX}/share/emacs/site-lisp\"" >> local.h

do-install:
	${CP} ${WRKSRC}/languages/${DICT_LANG}/${DICT_LANG}xlg.hash ${PREFIX}/lib
	cd ${PREFIX}/lib;						\
	${RM} -f ${DICT_LANG}.hash;					\
	${LN} ${DICT_LANG}xlg.hash ${DICT_LANG}.hash

.include "../../mk/bsd.pkg.mk"
