# $NetBSD: Makefile,v 1.22 2020/05/12 11:27:58 nia Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.23
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://web.archive.org/web/20091027154331/http://geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20091027032434/http://geocities.com/SiliconValley/Foothills/4078/
COMMENT=	Disassembler for Win32 code

WRKSRC=		${WRKDIR}

# LP64 problems
BROKEN_ON_PLATFORM=	${LP64PLATFORMS}

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
