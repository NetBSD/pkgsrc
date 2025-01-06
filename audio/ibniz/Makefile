# $NetBSD: Makefile,v 1.4 2025/01/06 21:49:01 ktnb Exp $
#

DISTNAME=	ibniz-1.18
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://pelulamu.net/ibniz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pelulamu.net/ibniz/
COMMENT=	Virtual machine designed for extremely compact audiovisual programs
LICENSE=	zlib

INSTALLATION_DIRS=	bin share/doc/ibniz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ibniz ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ibniz.txt ${DESTDIR}${PREFIX}/share/doc/ibniz

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
