# $NetBSD: Makefile,v 1.5 2001/11/29 01:12:49 hubertf Exp $
#

DISTNAME=	ispell-3.1.20
PKGNAME=	ispell-base-3.1.20
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	Interactive spelling checker

CONFLICTS+=	ispell-[0-9]*

MAKE_FLAGS+=	TMPDIR="${WRKDIR}"

WRKSRC=		${WRKDIR}/ispell-3.1

USE_GTEXINFO=	yes
INFO_FILES=	ispell.info

.if exists(/usr/include/inttypes.h)
CFLAGS+=	-DHAVE_INTTYPES_H
.endif

USE_BUILDLINK_ONLY=	yes

do-configure:
	cd ${WRKSRC};							\
	${SED} -e 's|/usr/local|${PREFIX}|g' <local.h.samp >local.h;	\
	${ECHO} "#undef NO8BIT" >> local.h ;				\
	${ECHO} "#define LANGUAGES \"{american,MASTERDICTS=american.med+,HASHFILES=americanmed+.hash,EXTRADICT=/usr/share/dict/words}\""  >>local.h; \
	${ECHO} "#define MASKBITS 64" >>local.h;			\
	${ECHO} "#undef WORDS"  >> local.h ;				\
	${ECHO} '#define WORDS   "/usr/share/dict/words"'  >> local.h ;	\
	${ECHO} '#undef ELISPDIR'  >> local.h;				\
	${ECHO} "#define ELISPDIR \"${PREFIX}/share/emacs/site-lisp\"" >> local.h; \
	${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> local.h

.include "../../mk/bsd.pkg.mk"
