# $NetBSD: Makefile,v 1.12 2010/01/27 17:13:24 joerg Exp $
#

DISTNAME=		hashcash-1.22
CATEGORIES=		security
MASTER_SITES=		http://www.hashcash.org/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hashcash.org/
COMMENT=		Hash collision based postage stamp

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-Dunix
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hashcash ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/hashcash.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
