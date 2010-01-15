# $NetBSD: Makefile,v 1.9 2010/01/15 21:05:56 zafer Exp $

DISTNAME=	9e
PKGNAME=	9e-1.0
CATEGORIES=	plan9 archivers
MASTER_SITES=	http://distfiles.aydogan.net/archivers/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eecs.harvard.edu/~wkj/Software/9e/
COMMENT=	Explode Plan9 archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
