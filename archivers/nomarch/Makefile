# $NetBSD: Makefile,v 1.13 2008/06/01 14:28:37 obache Exp $
#

DISTNAME=	nomarch-1.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/nomarch.html
COMMENT=	Free replacement for the arc program

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${DESTDIR}${PREFIX}/bin/nomarch
	${INSTALL_MAN} ${WRKSRC}/nomarch.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nomarch.1

.include "../../mk/bsd.pkg.mk"
