# $NetBSD: Makefile,v 1.10 2004/04/25 09:15:39 snj Exp $
#

DISTNAME=	gkx86info0.0.2
PKGNAME=	gkx86info-0.0.2
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://asdfnews.org/yargon/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://asdfnews.org/yargon/
COMMENT=	Gkrellm plugin that prints the current clock speed

USE_BUILDLINK3=		YES
ONLY_FOR_PLATFORM=	*-*-i386

pre-build:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
