# $NetBSD: Makefile,v 1.2 2001/02/16 14:38:56 wiz Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.22
NO_WRKSUBDIR=	yes
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/
COMMENT=	disassembler for Win32 code

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
