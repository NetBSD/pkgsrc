# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:52 jlam Exp $
#

DISTNAME=	pcf2bdf-1.04
CATEGORIES=	fonts graphics x11
MASTER_SITES=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
COMMENT=	Convert X font from PCF to BDF

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKEFILE=	Makefile.gcc

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcf2bdf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pcf2bdf.man ${PREFIX}/man/man1/pcf2bdf.1

.include "../../mk/bsd.pkg.mk"
