# $NetBSD: Makefile,v 1.48 2019/08/11 13:22:42 wiz Exp $

DISTNAME=	psutils-p17
PKGNAME=	psutils-1.17
PKGREVISION=	9
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.knackered.org/pub/psutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://knackered.org/angus/psutils/
COMMENT=	Utilities for manipulating PostScript documents

WRKSRC=		${WRKDIR}/psutils
USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	PAPERSIZE

.if !defined(PAPERSIZE)
PKG_FAIL_REASON+=	"PAPERSIZE must be defined by the pkgsrc user."
.else
.  if ${PAPERSIZE} != "A4" && ${PAPERSIZE} != "Letter"
PKG_FAIL_REASON+=	"Invalid PAPERSIZE (${PAPERSIZE}). Choose one of A4 or Letter."
.  endif
.endif

MAKE_ENV+=	PERL5=${PERL5:Q}
MAKE_FLAGS+=	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`
MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_FILE=	Makefile.unix

EGDIR=		${PREFIX}/share/examples/psutils
CONF_FILES=	${EGDIR}/psutils.cfg ${PKG_SYSCONFDIR}/psutils.cfg

SUBST_CLASSES+=		psu
SUBST_STAGE.psu=	pre-configure
SUBST_MESSAGE.psu=	Adjusting the installation prefix.
SUBST_FILES.psu=	psutil.c
SUBST_SED.psu=		-e "s|@prefix@|${PREFIX}|g"

INSTALLATION_DIRS=	${EGDIR}
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

post-install:
	low=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`		\
	&& ${ECHO} "PAPERSIZE=$$low" > ${DESTDIR}${EGDIR}/psutils.cfg

.include "../../mk/bsd.pkg.mk"
