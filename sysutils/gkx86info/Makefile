# $NetBSD: Makefile,v 1.2 2002/08/12 00:32:27 dmcmahill Exp $
#

DISTNAME=	gkx86info0.0.2
PKGNAME=	gkx86info-0.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://asdfnews.org/yargon/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://asdfnews.org/yargon/
COMMENT=	gkrellm plugin that prints the current clock speed

DEPENDS+=	gkrellm>=1.2:../../sysutils/gkrellm

ONLY_FOR_PLATFORM=	*-*-i386

pre-build:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
