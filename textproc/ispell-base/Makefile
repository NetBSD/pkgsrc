# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 12:10:22 agc Exp $
#

DISTNAME=	ispell-3.1.20
PKGNAME=	ispell-base-3.1.20
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	Interactive spelling checker

CONFLICTS+=	ispell-[0-9]*

WRKSRC=		${WRKDIR}/ispell-3.1

USE_GTEXINFO=	yes
INFO_FILES=	ispell.info

.if exists(/usr/include/inttypes.h)
CFLAGS+=	-DHAVE_INTTYPES_H
.endif

do-configure:
	cd ${WRKSRC};							\
	${SED} -e 's|/usr/local|${PREFIX}|g' <local.h.samp >local.h;	\
	${ECHO} "#undef NO8BIT" >> local.h ;				\
	${ECHO} "#define LANGUAGES \"{american,MASTERDICTS=american.med+,HASHFILES=americanmed+.hash,EXTRADICT=/usr/share/dict/words}\""  >>local.h; \
	${ECHO} "#undef WORDS"  >> local.h ;				\
	${ECHO} '#define WORDS   "/usr/share/dict/words"'  >> local.h ;	\
	${ECHO} '#undef ELISPDIR'  >> local.h;				\
	${ECHO} "#define ELISPDIR \"${PREFIX}/share/emacs/site-lisp\"" >> local.h; \
	${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> local.h

.include "../../mk/bsd.pkg.mk"
