# $NetBSD: Makefile,v 1.1.1.1 2002/12/31 05:44:43 kei Exp $
#

DISTNAME=	pcf2bdf-1.04
CATEGORIES=	fonts graphics x11
MASTER_SITES=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.tsg.ne.jp/GANA/S/pcf2bdf/
COMMENT=	convert X font from PCF to BDF

USE_GMAKE=	YES
WRKSRC=		${WRKDIR}
MAKEFILE=	Makefile.gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcf2bdf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pcf2bdf.man ${PREFIX}/man/man1/pcf2bdf.1

.include "../../mk/bsd.pkg.mk"
