# $NetBSD: Makefile,v 1.5 2005/09/28 20:59:08 seb Exp $

DISTNAME=	vip-19971113
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.duke.edu/~des/scripts/
DISTFILES=	vip vip.man

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.cs.duke.edu/~des/vip.html
COMMENT=	Script to edit the data at any point in a pipeline

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin man/man8

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/vip ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/vip.man ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vip ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vip.man ${PREFIX}/man/man8/vip.8

.include "../../mk/bsd.pkg.mk"
