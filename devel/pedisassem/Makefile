# $NetBSD: Makefile,v 1.11 2004/03/13 17:24:31 kristerw Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.23
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/
COMMENT=	Disassembler for Win32 code

WRKSRC=		${WRKDIR}

# LP64 problems
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64 *-*-x86_64

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
