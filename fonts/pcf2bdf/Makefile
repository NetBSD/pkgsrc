# $NetBSD: Makefile,v 1.3 2003/07/17 21:37:35 grant Exp $
#

DISTNAME=	pcf2bdf-1.04
WRKSRC=		${WRKDIR}
CATEGORIES=	fonts graphics x11
MASTER_SITES=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
COMMENT=	convert X font from PCF to BDF

USE_GMAKE=	YES
MAKEFILE=	Makefile.gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcf2bdf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pcf2bdf.man ${PREFIX}/man/man1/pcf2bdf.1

.include "../../mk/bsd.pkg.mk"
