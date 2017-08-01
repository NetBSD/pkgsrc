# $NetBSD: Makefile,v 1.1 2017/08/01 15:06:24 wiz Exp $

DISTNAME=	mandoc-1.14.2
CATEGORIES=	textproc devel
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/

MAINTAINER=	schwarze@usta.de
HOMEPAGE=	http://mdocml.bsd.lv/
COMMENT=	Convert man pages from mdoc, man, and tbl to txt, html, ps, or pdf
LICENSE=	2-clause-bsd # not exactly, but near enough

HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/rc[0-9]*//}

SUBST_CLASSES+=		roff
SUBST_STAGE.roff=	pre-build
SUBST_FILES.roff=	mandoc.1 mandoc.3
SUBST_FILES.roff+=	eqn.7 man.7 mdoc.7 tbl.7
SUBST_SED.roff=		-e 's,Xr roff,Xr mandoc-roff,g'

# test needs perl
USE_TOOLS+=	perl:build
TEST_TARGET=	regress

.include "../../mk/bsd.fast.prefs.mk"

post-extract:
	${ECHO} PREFIX=${PREFIX} > ${WRKSRC}/configure.local
	${ECHO} MANDIR=${PREFIX}/${PKGMANDIR} >> ${WRKSRC}/configure.local
	${ECHO} CFLAGS=\"${CFLAGS:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} LDFLAGS=\"${LDFLAGS:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} LD_SQLITE3=\"${LDFLAGS} -lsqlite3\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL=\"${INSTALL:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_PROGRAM=\"${INSTALL_PROGRAM:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_LIB=\"${INSTALL_DATA:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_MAN=\"${INSTALL_MAN:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_DATA=\"${INSTALL_DATA:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} MANM_ROFF="mandoc-roff" >> ${WRKSRC}/configure.local
	${ECHO} BINM_SOELIM="msoelim" >> ${WRKSRC}/configure.local
# Need -lrt for nanosleep(2) on Solaris.
.if ${OPSYS} == "SunOS"
	${ECHO} LDADD=\"-lrt\" >> ${WRKSRC}/configure.local
.endif
# Mac OS X and Solaris 10 and newer do not support static binaries.
.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
	${ECHO} STATIC= >> ${WRKSRC}/configure.local
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
