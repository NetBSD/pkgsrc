# $NetBSD: Makefile,v 1.5 2002/09/26 17:25:46 jschauma Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.23
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/
COMMENT=	disassembler for Win32 code

WRKSRC=		${WRKDIR}

# LP64 problems
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
