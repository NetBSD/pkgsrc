# $NetBSD: Makefile,v 1.16 2006/03/04 21:29:26 jlam Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.23
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/
COMMENT=	Disassembler for Win32 code

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

# LP64 problems
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64 *-*-x86_64

MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
