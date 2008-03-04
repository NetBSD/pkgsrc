# $NetBSD: Makefile,v 1.12 2008/03/04 19:21:11 jlam Exp $
#

DISTNAME=	cuetools-1.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://download.berlios.de/cuetools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cuetools.berlios.de/
COMMENT=	Set of utilities to manipulate cue and toc files

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	flex gmake yacc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cuebreakpoints \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cueconvert \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cueprint \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/cuebreakpoints.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cuebreakpoints.1
	${INSTALL_DATA} ${WRKSRC}/man/cueconvert.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cueconvert.1
	${INSTALL_DATA} ${WRKSRC}/man/cueprint.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cueprint.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cuetools/
	${INSTALL_DATA} ${WRKSRC}/formats.txt \
		${DESTDIR}${PREFIX}/share/doc/cuetools/

.include "../../mk/bsd.pkg.mk"
