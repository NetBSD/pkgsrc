# $NetBSD: Makefile,v 1.3 2002/09/24 10:42:12 jlam Exp $
#

DISTNAME=	kdrill5.11.6
PKGNAME=	kdrill-5.11.6
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.bolthole.com/kdrill/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bolthole.com/kdrill/
COMMENT=	kanji quiz and japanese dictionary

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
