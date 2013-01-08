# $NetBSD: Makefile,v 1.1 2013/01/08 09:48:58 wiz Exp $
#

DISTNAME=	ibniz-1.18
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
