# $NetBSD: Makefile,v 1.26 2005/12/05 20:51:03 rillig Exp $
#

DISTNAME=	ispell-3.3.02
PKGNAME=	ispell-base-3.3.02
CATEGORIES=	textproc
MASTER_SITES=	http://fmg-www.cs.ucla.edu/geoff/tars/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ficus-www.cs.ucla.edu/geoff/ispell.html
COMMENT=	Interactive spelling checker

CONFLICTS+=	ispell-[0-9]*

USE_TOOLS+=	mktemp:run

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/inttypes.h) && ${LOWER_OPSYS} != "irix5.3"
CFLAGS+=	-DHAVE_INTTYPES_H
.endif


.if ${OPSYS} == "SunOS"
EXTRADICT=/usr/dict/words
.else
EXTRADICT=/usr/share/dict/words
.endif

.if !exists(${EXTRADICT})
EXTRADICT=
.endif

do-configure:
	cd ${WRKSRC};							\
	${SED} -e 's|/usr/local|${PREFIX}|g' <local.h.bsd >local.h;	\
	${ECHO} "#define LANGUAGES \"{american,MASTERDICTS=american.med+,HASHFILES=americanmed+.hash,EXTRADICT=${EXTRADICT}}\""  >>local.h; \
	${ECHO} "#define MASTERHASH \"americanmed+.hash\"" >>local.h;	\
	${ECHO} "#define MASKBITS 64" >>local.h;			\
	${ECHO} "#undef WORDS"  >> local.h ;				\
	${ECHO} '#define WORDS   "${EXTRADICT}"'  >> local.h ;		\
	${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> local.h
.if ${OPSYS} == "SunOS"
	cd ${WRKSRC};							\
	${ECHO} "#define USG" >> local.h;
.endif
.if ${OPSYS} == "Interix"
	cd ${WRKSRC};							\
	${ECHO} "#define SORTTMP \"\"" >> local.h;			\
	${ECHO} "#define MAKE_SORTTMP \"\"" >> local.h;
.endif

.include "../../mk/bsd.pkg.mk"
