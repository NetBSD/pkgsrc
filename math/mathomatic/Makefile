# $NetBSD: Makefile,v 1.8 2004/05/04 17:20:49 minskim Exp $
#

DISTNAME=		mathomatic-11.0f
CATEGORIES=		math
MASTER_SITES=		http://www.panix.com/~gesslein/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.panix.com/~gesslein/
COMMENT=		Small portable symbolic math program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/am
DIST_SUBDIR=		${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes
MAKEFILE=		makefile

CFLAGS.SunOS+=		-DSOLARIS

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/readline/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/am ${PREFIX}/bin/am_mathomatic
	${INSTALL_MAN} ${WRKSRC}/am.1 ${PREFIX}/man/man1/am_mathomatic.1

.include "../../mk/bsd.pkg.mk"
