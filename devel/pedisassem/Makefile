# $NetBSD: Makefile,v 1.3 2001/04/18 20:38:21 dmcmahill Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.22
NO_WRKSUBDIR=	yes
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
