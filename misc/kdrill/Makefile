# $NetBSD: Makefile,v 1.8 2003/07/21 17:01:16 martti Exp $
#

DISTNAME=	kdrill5.11.6
PKGNAME=	kdrill-5.11.6
PKGREVISION=	1
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.bolthole.com/kdrill/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bolthole.com/kdrill/
COMMENT=	Kanji quiz and japanese dictionary

USE_BUILDLINK2=	yes
USE_IMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kdrill
	cd ${WRKSRC}/makedic && \
	${INSTALL_DATA} hira.edic hiraplus.edic kata.edic kataplus.edic \
		fullkatahira.edic ${PREFIX}/share/kdrill
	for f in hira.edic hiraplus.edic kata.edic kataplus.edic \
		fullkatahira.edic; do \
		${GZIP_CMD} -9 ${PREFIX}/share/kdrill/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
