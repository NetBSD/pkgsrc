# $NetBSD: Makefile,v 1.1 2020/01/10 16:57:24 plunky Exp $

DISTNAME=	libtcd-2.2.7-r2
PKGNAME=	${DISTNAME:S/-r/r/}
CATEGORIES=	databases
MASTER_SITES=	https://flaterco.com/files/xtide/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flaterco.com/
COMMENT=	API for reading and writing Tide Constituent Database (TCD) files
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${DISTNAME:C/-r.*//}

GNU_CONFIGURE=	yes
USE_TOOLS=	bash gmake gsed
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
