# $NetBSD: Makefile,v 1.4 2011/03/11 11:19:55 zafer Exp $
#

DISTNAME=	xmake-1.06
CATEGORIES=	devel
MASTER_SITES=	# http://apollo.backplane.com/xmake/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://apollo.backplane.com/xmake/
COMMENT=	Portable make utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	IBDIR=${DESTDIR}${PREFIX}/bin \
			IMDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
