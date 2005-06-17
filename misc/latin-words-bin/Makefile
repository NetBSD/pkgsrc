# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:22 jlam Exp $
#

DISTNAME=		words-1.97-linux
PKGNAME=		latin-words-bin-1.97
CATEGORIES=		misc
MASTER_SITES=		ftp://petrus.thomasaquinas.edu/pub/linux/words/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://users.erols.com/whitaker/wordslux.htm
COMMENT=		Latin-to-English dictionary program (Linux binary)

WRKSRC=			${WRKDIR}/words-1.97
NO_CONFIGURE=   YES

CHECK_SHLIBS=   NO

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
.endif

INSTALLATION_DIRS=	bin libexec

do-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/latin-words.sh \
		> ${WRKSRC}/latin-words

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latin-words ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/words ${PREFIX}/libexec/latin-words
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/latin-words
.for f in ADDONS.LAT DICTFILE.GEN INDXFILE.GEN INFLECTS.SEC \
	STEMFILE.GEN UNIQUES.LAT
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/libdata/latin-words
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/latin-words
.for f in README wordsdoc.html wordsdoc.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/latin-words
.endfor

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
