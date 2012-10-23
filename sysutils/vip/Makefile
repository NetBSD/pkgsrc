# $NetBSD: Makefile,v 1.10 2012/10/23 19:51:29 asau Exp $

DISTNAME=	vip-19971113
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.duke.edu/~des/scripts/
DISTFILES=	vip vip.man

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.duke.edu/~des/vip.html
COMMENT=	Script to edit the data at any point in a pipeline

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/vip ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/vip.man ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vip ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vip.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/vip.8

.include "../../mk/bsd.pkg.mk"
