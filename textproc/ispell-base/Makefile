# $NetBSD: Makefile,v 1.6.2.2 2002/08/25 21:21:40 jlam Exp $
#

DISTNAME=	ispell-3.1.20
PKGNAME=	ispell-base-3.1.20
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

PATCH_SITES=	ftp://kdstevens.com/pub/stevens/
PATCHFILES=    ispell-patch1.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	Interactive spelling checker

CONFLICTS+=	ispell-[0-9]*

MAKE_FLAGS+=	TMPDIR="${WRKDIR}"

WRKSRC=		${WRKDIR}/ispell-3.1

INFO_FILES=	ispell.info

.if exists(/usr/include/inttypes.h)
CFLAGS+=	-DHAVE_INTTYPES_H
.endif

USE_BUILDLINK2=	yes

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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
