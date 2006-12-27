# $NetBSD: Makefile,v 1.16 2006/12/27 13:37:39 joerg Exp $
#

DISTNAME=	kdrill5.11.6
PKGNAME=	kdrill-5.11.6
PKGREVISION=	3
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.bolthole.com/kdrill/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bolthole.com/kdrill/
COMMENT=	Kanji quiz and japanese dictionary

DEPENDS+=	edict-[0-9]*:../../misc/edict
DEPENDS+=	kanjidic-[0-9]*:../../misc/kanjidic

USE_IMAKE=	yes
USE_TOOLS+=	gzip

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

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
