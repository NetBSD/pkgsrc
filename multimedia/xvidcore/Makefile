# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 12:38:26 jmmv Exp $
#

DISTNAME=	xvidcore-0.9.2
CATEGORIES=	multimedia
MASTER_SITES=	http://files.xvid.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xvid.org/
COMMENT=	ISO MPEG-4 compliant video codec

BUILD_DEPENDS+=	nasm>=0.98.34:../../devel/nasm

WRKSRC=		${WRKDIR}/${DISTNAME}/build/generic
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
