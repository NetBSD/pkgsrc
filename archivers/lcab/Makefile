# $NetBSD: Makefile,v 1.9 2008/07/28 19:42:33 plunky Exp $
#

DISTNAME=		lcab-1.0b12
CATEGORIES=		archivers
MASTER_SITES=		http://lcab.move-to-cork.com/sources/

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://lcab.move-to-cork.com/
COMMENT=		Microsoft cabinet (.CAB) file creator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/lcab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
