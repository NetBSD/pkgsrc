# $NetBSD: Makefile,v 1.12 2023/12/23 09:23:23 zafer Exp $

DISTNAME=	vip-19971113
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://users.cs.duke.edu/~des/scripts/
DISTFILES=	vip vip.man

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.duke.edu/~des/vip.html
COMMENT=	Script to edit the data at any point in a pipeline

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
