# $NetBSD: Makefile,v 1.2 2004/05/07 11:27:16 jmmv Exp $
#

DISTNAME=	cuetools-0.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cuetools/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://cuetools.sourceforge.net/
COMMENT=	Set of utilities to manipulate cue and toc files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cueconvert ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/cuerename ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/cueconvert.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/man/cuerename.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cuetools/
	${INSTALL_DATA} ${WRKSRC}/doc/formats ${PREFIX}/share/doc/cuetools/
	${INSTALL_DATA} ${WRKSRC}/doc/useage ${PREFIX}/share/doc/cuetools/usage
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cuetools/
	${INSTALL_DATA} ${WRKSRC}/doc/cuerename \
	    ${PREFIX}/share/examples/cuetools/cuerename

.include "../../mk/bsd.pkg.mk"
