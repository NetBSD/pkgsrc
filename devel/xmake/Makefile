# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:31 wiz Exp $
#

DISTNAME=	xmake-1.06
CATEGORIES=	devel
MASTER_SITES=	# http://apollo.backplane.com/xmake/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://apollo.backplane.com/xmake/
COMMENT=	Portable make utility

WRKSRC=		${WRKDIR}/xmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	IBDIR=${DESTDIR}${PREFIX}/bin \
			IMDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
