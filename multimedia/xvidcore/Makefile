# $NetBSD: Makefile,v 1.4 2004/03/28 23:09:51 snj Exp $
#

DISTNAME=	xvidcore-1.0.0-rc3
PKGNAME=	xvidcore-1.0.0
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

MAKE_ENV+=	MKDIR="${MKDIR}"

.include "../../mk/bsd.pkg.mk"
