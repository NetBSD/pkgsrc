# $NetBSD: Makefile,v 1.1.1.1 2002/12/05 15:02:24 wiz Exp $
#

DISTNAME=	GutenMark-words-20021124
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.sandroid.org/GutenMark/Wordlists/
DISTFILES=	${WORDLISTS} GutenMark.cfg

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.sandroid.org/GutenMark/
COMMENT=	word lists for GutenMark

WORDLISTS=	special.words.gz english.names.gz US.places.gz \
		french.names.gz english.words.gz french.words.gz \
		german2.words.gz german.words.gz latin.words.gz \
		italian.words.gz spanish.words.gz NonUS.places.gz \
		norwegian.words.gz gaelic.words.gz danish.words.gz \
		swedish.words.gz finnish.words.gz nonenglish.words.gz
SITES_GutenMark.cfg=http://www.sandroid.org/GutenMark/

DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	YES
WRKSRC=		${WRKDIR}

post-extract:
	${CP} ${_DISTDIR}/GutenMark.cfg ${WRKDIR}/GutenMark.cfg.in

do-build:
	cd ${WRKDIR} && ${SED} "s|@@PREFIX@@|${PREFIX}|g" \
		GutenMark.cfg.in > GutenMark.cfg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/GutenMark
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/GutenMark
	for wl in ${WORDLISTS}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$wl ${PREFIX}/share/GutenMark; \
	done
	${INSTALL_DATA} ${WRKDIR}/GutenMark.cfg \
		${PREFIX}/share/examples/GutenMark

.include "../../mk/bsd.pkg.mk"
