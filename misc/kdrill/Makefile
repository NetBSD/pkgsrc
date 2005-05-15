# $NetBSD: Makefile,v 1.12 2005/05/15 22:02:27 jlam Exp $
#

DISTNAME=	kdrill5.11.6
PKGNAME=	kdrill-5.11.6
PKGREVISION=	2
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.bolthole.com/kdrill/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bolthole.com/kdrill/
COMMENT=	Kanji quiz and japanese dictionary

DEPENDS+=	edict-[0-9]*:../../misc/edict
DEPENDS+=	kanjidic-[0-9]*:../../misc/kanjidic

USE_IMAKE=		yes
PKGSRC_USE_TOOLS+=	gzip

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kdrill
	cd ${WRKSRC}/makedic && \
	${INSTALL_DATA} hira.edic hiraplus.edic kata.edic kataplus.edic \
		fullkatahira.edic ${PREFIX}/share/kdrill
	for f in hira.edic hiraplus.edic kata.edic kataplus.edic \
		fullkatahira.edic; do \
		${GZIP_CMD} -9 ${PREFIX}/share/kdrill/$$f; \
	done
	${GZIP_CMD} -c ${PREFIX}/share/edict/edict > \
		${PREFIX}/share/kdrill/edict.gz
	${GZIP_CMD} -c ${PREFIX}/share/kanjidic/kanjidic > \
		${PREFIX}/share/kdrill/kanjidic.gz

.include "../../mk/bsd.pkg.mk"
