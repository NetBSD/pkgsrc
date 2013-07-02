# $NetBSD: Makefile,v 1.69 2013/07/02 19:47:48 adam Exp $

DISTNAME=	unrarsrc-5.0.7
PKGNAME=	${DISTNAME:S/src//}
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.rarlab.com/
COMMENT=	Extract, view & test RAR archives
LICENSE=	unrar-license
# From private mail addressed to pkgsrc maintainers:
#
# Date: Wed, 10 Sep 2008 18:27:35 +0600
# From: Eugene Roshal <roshal@rarlab.com>
# You can redistribute either original or modified binaries or sources.

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	YES
USE_LANGUAGES=	c++
# XXX: makefile has DOS line endings
USE_TOOLS+=	gmake

MAKE_FILE=	makefile
MAKEFLAGS+=	CXX=${CXX:Q} CXXFLAGS=${CXXFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

WRKSRC=		${WRKDIR}/unrar

INSTALLATION_DIRS=	bin share/doc/unrar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt license.txt	\
		${DESTDIR}${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
