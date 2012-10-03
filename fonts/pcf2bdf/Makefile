# $NetBSD: Makefile,v 1.14 2012/10/03 18:28:29 asau Exp $
#

DISTNAME=	pcf2bdf-1.04
PKGREVISION=	1
CATEGORIES=	fonts graphics x11
MASTER_SITES=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
COMMENT=	Convert X font from PCF to BDF

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKE_FILE=	Makefile.gcc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcf2bdf ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pcf2bdf.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pcf2bdf.1

.include "../../mk/bsd.pkg.mk"
