# $NetBSD: Makefile,v 1.7 2005/03/24 21:12:50 wiz Exp $

DISTNAME=	makeself-1.5.3
CATEGORIES=	archivers
MASTER_SITES=	http://linuxberg.tele.net/files/console/file/
EXTRACT_SUFX=	.gz.sh

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.megastep.org/makeself/
COMMENT=	Neat script to make self-extracting archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKDIR}
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

# The DISPLAY thing is to prevent the script from trying to launch a xterm
# just to extract the source.
pre-patch:
	(cd ${WRKDIR} && ${SETENV} DISPLAY="" ${SH} ${DISTFILES})

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/makeself.sh ${PREFIX}/bin/makeself

.include "../../mk/bsd.pkg.mk"
