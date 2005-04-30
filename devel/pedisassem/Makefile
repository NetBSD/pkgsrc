# $NetBSD: Makefile,v 1.12 2005/04/30 17:10:30 minskim Exp $

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

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
