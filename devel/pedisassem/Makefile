# $NetBSD: Makefile,v 1.1.1.1 2001/01/24 18:06:35 itojun Exp $

DISTNAME=	dsasmsrc
PKGNAME=	pedisassem-0.22
NO_WRKSUBDIR=	yes
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Foothills/4078/

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
