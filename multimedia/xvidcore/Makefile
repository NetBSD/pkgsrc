# $NetBSD: Makefile,v 1.2 2004/02/20 17:23:44 jmmv Exp $
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
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
