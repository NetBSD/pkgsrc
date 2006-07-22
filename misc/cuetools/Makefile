# $NetBSD: Makefile,v 1.10 2006/07/22 00:45:10 minskim Exp $
#

DISTNAME=	cuetools-1.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://download.berlios.de/cuetools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cuetools.berlios.de/
COMMENT=	Set of utilities to manipulate cue and toc files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	flex gmake yacc

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cuebreakpoints ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cueconvert ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cueprint ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/cuebreakpoints.man \
		${PREFIX}/man/man1/cuebreakpoints.1
	${INSTALL_DATA} ${WRKSRC}/man/cueconvert.man \
		${PREFIX}/man/man1/cueconvert.1
	${INSTALL_DATA} ${WRKSRC}/man/cueprint.man \
		${PREFIX}/man/man1/cueprint.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cuetools/
	${INSTALL_DATA} ${WRKSRC}/formats.txt ${PREFIX}/share/doc/cuetools/

.include "../../mk/bsd.pkg.mk"
