# $NetBSD: Makefile,v 1.3 2021/12/08 16:06:12 adam Exp $

DISTNAME=	brlaser-v6
PKGNAME=	${DISTNAME:S/-v/-/}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=pdewacht/}
GITHUB_PROJECT=	brlaser
GITHUB_TAG=	v6

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/pdewacht/brlaser/
COMMENT=	CUPS driver for Brother laser printers
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/brlaser-6
USE_CMAKE=	yes
USE_LANGUAGES=	c++11

.include "../../print/libcups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
