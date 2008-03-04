# $NetBSD: Makefile,v 1.7 2008/03/04 06:59:03 jlam Exp $
#

DISTNAME=		cmatrix-1.2a
CATEGORIES=		games
MASTER_SITES=		http://www.asty.org/cmatrix/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.asty.org/cmatrix/
COMMENT=		Make your console feel like Nadbuchonazor's bridge

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${DESTDIR}${PREFIX}/bin/cmatrix
	${INSTALL_MAN} ${WRKSRC}/cmatrix.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cmatrix.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/cmatrix
	${INSTALL_DATA} ${WRKSRC}/mtx.pcf \
		${DESTDIR}${PREFIX}/share/cmatrix/mtx.pcf

.include "../../mk/bsd.pkg.mk"
