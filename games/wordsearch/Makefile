# $NetBSD: Makefile,v 1.5 2023/10/23 06:37:46 wiz Exp $

DISTNAME=	wordsearch-2.1
PKGREVISION=	3
CATEGORIES=	games
GITHUB_PROJECT=	wordsearch
MASTER_SITES=	${MASTER_SITE_GITHUB:=jensenpat/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	patj@passpackets.com
HOMEPAGE=	https://github.com/jensenpat/wordsearch/
COMMENT=	Classic word search game that you can play in your terminal
LICENSE=	2-clause-bsd

NO_BUILD=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=	wordsearch

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 share/wordsearch

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	wordsearch
SUBST_SED.prefix=	-e 's,/usr/pkg/share,${PREFIX}/share,g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wordsearch ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/wordsearch.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/
	${INSTALL_DATA} ${WRKSRC}/puzzles/*.txt ${DESTDIR}${PREFIX}/share/wordsearch/

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
