# $NetBSD: Makefile,v 1.6 2003/03/29 12:40:37 jmmv Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.23
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/
COMMENT=	disassembler for Win32 code

# LP64 problems
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
