# $NetBSD: Makefile,v 1.2.2.1 2002/05/11 02:08:53 jlam Exp $
#

DISTNAME=	nulibdist
PKGNAME=	nulib2-1.0.1
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.nulib.com/
COMMENT=	Handles Apple II ShrinkIt (NuFX) file/disk archives

WRKSRC=		${WRKDIR}/nulib2-101

USE_BUILDLINK2_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--cache-file=${WRKDIR}/config.cache

.include "../../mk/bsd.pkg.mk"

# nulib2 needs this to identify a Unixlike system
CFLAGS+=	-D__unix__
