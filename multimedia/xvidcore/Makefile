# $NetBSD: Makefile,v 1.10 2005/01/18 13:04:13 drochner Exp $
#

DISTNAME=	xvidcore-1.0.3
CATEGORIES=	multimedia
MASTER_SITES=	http://files.xvid.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xvid.org/
COMMENT=	ISO MPEG-4 compliant video codec

ONLY_FOR_PLATFORM+=	*-*-i386

BUILD_DEPENDS+=	nasm>=0.98.34:../../devel/nasm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/build/generic
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

MAKE_ENV+=	MKDIR="${MKDIR}"

.include "../../mk/bsd.pkg.mk"
