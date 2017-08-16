# $NetBSD: Makefile,v 1.11 2017/08/16 20:45:41 wiz Exp $
#

DISTNAME=		words-1.97-linux
PKGNAME=		latin-words-bin-1.97
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		ftp://petrus.thomasaquinas.edu/pub/linux/words/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://users.erols.com/whitaker/wordslux.htm
COMMENT=		Latin-to-English dictionary program (Linux binary)

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}/words-1.97
INSTALLATION_DIRS=	bin libexec

do-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/latin-words.sh \
		> ${WRKSRC}/latin-words

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latin-words ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/words \
		${DESTDIR}${PREFIX}/libexec/latin-words
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libdata/latin-words
.for f in ADDONS.LAT DICTFILE.GEN INDXFILE.GEN INFLECTS.SEC \
	STEMFILE.GEN UNIQUES.LAT
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/libdata/latin-words
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/latin-words
.for f in README wordsdoc.html wordsdoc.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/latin-words
.endfor

.include "../../mk/bsd.pkg.mk"
