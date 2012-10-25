# $NetBSD: Makefile,v 1.11 2012/10/25 06:55:38 asau Exp $
#

DISTNAME=	GutenMark-words-20030107
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.sandroid.org/GutenMark/Wordlists/
DISTFILES=	${WORDLISTS} GutenMark.cfg

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sandroid.org/GutenMark/
COMMENT=	Word lists for GutenMark

WORDLISTS=	special.words.gz english.names.gz US.places.gz \
		french.names.gz english.words.gz french.words.gz \
		german2.words.gz german.words.gz latin.words.gz \
		italian.words.gz spanish.words.gz NonUS.places.gz \
		norwegian.words.gz gaelic.words.gz danish.words.gz \
		swedish.words.gz finnish.words.gz nonenglish.words.gz
SITES.GutenMark.cfg=http://www.sandroid.org/GutenMark/

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	share/GutenMark share/examples/GutenMark

post-extract:
	${CP} ${_DISTDIR}/GutenMark.cfg ${WRKDIR}/GutenMark.cfg.in

do-build:
	cd ${WRKDIR} && ${SED} "s|@@PREFIX@@|${PREFIX}|g" \
		GutenMark.cfg.in > GutenMark.cfg

do-install:
	for wl in ${WORDLISTS}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$wl ${DESTDIR}${PREFIX}/share/GutenMark; \
	done
	${INSTALL_DATA} ${WRKDIR}/GutenMark.cfg \
		${DESTDIR}${PREFIX}/share/examples/GutenMark

.include "../../mk/bsd.pkg.mk"
