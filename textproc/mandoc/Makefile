# $NetBSD: Makefile,v 1.17 2022/06/28 11:36:12 wiz Exp $

DISTNAME=	mandoc-1.14.6
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://mandoc.bsd.lv/snapshots/

MAINTAINER=	schwarze@usta.de
HOMEPAGE=	https://mandoc.bsd.lv/
COMMENT=	Convert man pages from mdoc, man, eqn and tbl to txt, html, ps, or pdf
LICENSE=	2-clause-bsd # not exactly, but near enough

HAS_CONFIGURE=	yes

SUBST_CLASSES+=		roff
SUBST_STAGE.roff=	pre-build
SUBST_FILES.roff=	mandoc.1 mandoc.3
SUBST_FILES.roff+=	eqn.7 man.7 mdoc.7 tbl.7
SUBST_SED.roff=		-e 's,Xr roff,Xr mandoc-roff,g'

#CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

USE_TOOLS+=	perl:test
TEST_TARGET=	regress

.include "../../mk/bsd.fast.prefs.mk"

post-extract:
	${ECHO} PREFIX=${PREFIX} > ${WRKSRC}/configure.local
	${ECHO} CFLAGS=\"${CFLAGS:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} LDFLAGS=\"${LDFLAGS:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL=\"${INSTALL:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_PROGRAM=\"${INSTALL_PROGRAM:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_LIB=\"${INSTALL_DATA:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_MAN=\"${INSTALL_MAN:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} INSTALL_DATA=\"${INSTALL_DATA:Q}\" >> ${WRKSRC}/configure.local
	${ECHO} MANDIR="${PREFIX}/${PKGMANDIR}" >> ${WRKSRC}/configure.local
	${ECHO} MANM_ROFF="mandoc-roff" >> ${WRKSRC}/configure.local
	${ECHO} BINM_SOELIM="msoelim" >> ${WRKSRC}/configure.local

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
