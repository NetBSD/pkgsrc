# $NetBSD: Makefile,v 1.18 2010/02/14 20:53:37 joerg Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.23
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/
COMMENT=	Disassembler for Win32 code

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

# LP64 problems
NOT_FOR_PLATFORM=	${LP64PLATFORMS}

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
