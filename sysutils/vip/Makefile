# $NetBSD: Makefile,v 1.2 2005/02/09 08:40:33 seb Exp $

DISTNAME=	vip-19971113
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.duke.edu/~des/scripts/
DISTFILES=	vip vip.man

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.cs.duke.edu/~des/vip.html
COMMENT=	Script to edit the data at any point in a pipeline

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

INSTALLATION_DIRS=	bin man/man8

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/vip ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/vip.man ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vip ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vip.man ${PREFIX}/man/man8/vip.8

.include "../../mk/bsd.pkg.mk"
