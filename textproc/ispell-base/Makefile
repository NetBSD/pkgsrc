# $NetBSD: Makefile,v 1.22 2005/03/24 17:08:02 tv Exp $
#

DISTNAME=	ispell-3.2.06
PKGNAME=	ispell-base-3.2.06
CATEGORIES=	textproc
MASTER_SITES=	http://fmg-www.cs.ucla.edu/geoff/tars/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ficus-www.cs.ucla.edu/geoff/ispell.html
COMMENT=	Interactive spelling checker

CONFLICTS+=	ispell-[0-9]*

MAKE_FLAGS+=	TMPDIR="${WRKDIR}"

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/inttypes.h) && ${LOWER_OPSYS} != "irix5.3"
CFLAGS+=	-DHAVE_INTTYPES_H
.endif

USE_BUILDLINK3=	yes

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
	${SED} -e 's|/usr/local|${PREFIX}|g' <local.h.samp >local.h;	\
	${ECHO} "#undef NO8BIT" >> local.h ;				\
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
