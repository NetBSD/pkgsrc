# $NetBSD: Makefile,v 1.3 2003/07/17 21:43:18 grant Exp $
#

DISTNAME=	xvidcore-0.9.1
WRKSRC=		${WRKDIR}/${DISTNAME}/build/generic
CATEGORIES=	graphics
MASTER_SITES=	http://files.xvid.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xvid.org/
COMMENT=	ISO MPEG-4 compliant video codec

BUILD_DEPENDS+=	nasm>=0.98.34:../../devel/nasm-devel

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
