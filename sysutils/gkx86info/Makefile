# $NetBSD: Makefile,v 1.13 2006/02/05 23:10:50 joerg Exp $
#

DISTNAME=	gkx86info0.0.2
PKGNAME=	gkx86info-0.0.2
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://asdfnews.org/yargon/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://asdfnews.org/yargon/
COMMENT=	Gkrellm plugin that prints the current clock speed

ONLY_FOR_PLATFORM=	*-*-i386

pre-build:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
