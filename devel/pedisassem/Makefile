# $NetBSD: Makefile,v 1.21 2015/01/04 02:20:16 dholland Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.23
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/
COMMENT=	Disassembler for Win32 code

WRKSRC=		${WRKDIR}

# LP64 problems
BROKEN_ON_PLATFORM=	${LP64PLATFORMS}

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
