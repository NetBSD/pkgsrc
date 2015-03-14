# $NetBSD: Makefile,v 1.27 2015/03/14 07:55:32 ryoon Exp $
#

DISTNAME=	ispell-3.4.00
CATEGORIES=	textproc
MASTER_SITES=	http://fmg-www.cs.ucla.edu/geoff/tars/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ficus-www.cs.ucla.edu/geoff/ispell.html
COMMENT=	Interactive spelling checker

CONFLICTS+=	ispell-base-[0-9]*
USE_TOOLS+=	gmake mktemp:run yacc
INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/inttypes.h) && empty(MACHINE_PLATFORM:MIRIX-5.3-*)
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
	${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> local.h ;		\
	${ECHO} "#define LIBES \"${LDFLAGS}\"" >> local.h ;		\
	${ECHO} "#define MAN1DIR \"${PREFIX}/${PKGMANDIR}/man1\"" >> local.h ; \
	${ECHO} "#define MAN45DIR \"${PREFIX}/${PKGMANDIR}/man5\"" >> local.h ;
.if ${OPSYS} == "SunOS"
	cd ${WRKSRC};							\
	${ECHO} "#define USG" >> local.h;
.endif
.if ${OPSYS} == "Interix"
	cd ${WRKSRC};							\
	${ECHO} "#define SORTTMP \"\"" >> local.h;			\
	${ECHO} "#define MAKE_SORTTMP \"\"" >> local.h;
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
