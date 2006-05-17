# $NetBSD: Makefile,v 1.11 2006/05/17 06:12:27 rillig Exp $

DISTNAME=	makeself-2.1.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.megastep.org/makeself/
EXTRACT_SUFX=	.run

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.megastep.org/makeself/
COMMENT=	Neat script to make self-extracting archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

# The DISPLAY thing is to prevent the script from trying to launch a xterm
# just to extract the source.
pre-patch:
	cd ${WRKDIR} && ${SETENV} DISPLAY="" ${SH} ${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makeself.sh ${PREFIX}/bin/makeself

.include "../../mk/bsd.pkg.mk"
