# $NetBSD: Makefile,v 1.1.1.1 2004/01/10 09:47:56 jmmv Exp $
#

DISTNAME=	cuetools-0.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cuetools/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://cuetools.sourceforge.net/
COMMENT=	Set of utilities to manipulate cue and toc files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cuebreakpoints ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/cueconvert ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/cuerename ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cuetools/
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.useage \
	    ${PREFIX}/share/doc/cuetools/usage
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cuetools/
	${INSTALL_DATA} ${WRKSRC}/README.formats ${PREFIX}/share/doc/cuetools/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cuetools/
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.cuerenamerc \
	    ${PREFIX}/share/examples/cuetools/cuerenamerc

.include "../../mk/bsd.pkg.mk"
