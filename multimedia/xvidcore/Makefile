# $NetBSD: Makefile,v 1.16 2006/02/05 23:10:19 joerg Exp $
#

DISTNAME=	xvidcore-1.1.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xvid.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xvid.org/
COMMENT=	ISO MPEG-4 compliant video codec

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-powerpc *-*-x86_64

BUILD_DEPENDS+=	nasm>=0.98.34:../../devel/nasm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/build/generic
GNU_CONFIGURE=	YES

MAKE_ENV+=	MKDIR=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
