# $NetBSD: Makefile,v 1.4 2003/05/03 20:52:06 wiz Exp $
#

DISTNAME=	gkx86info0.0.2
PKGREVISION=	1
PKGNAME=	gkx86info-0.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://asdfnews.org/yargon/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://asdfnews.org/yargon/
COMMENT=	gkrellm plugin that prints the current clock speed

USE_BUILDLINK2=		YES
ONLY_FOR_PLATFORM=	*-*-i386

pre-build:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
