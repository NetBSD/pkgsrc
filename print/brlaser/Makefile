# $NetBSD: Makefile,v 1.8 2023/04/19 08:11:17 adam Exp $

DISTNAME=	brlaser-6.2
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=QORTEC/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/QORTEC/brlaser/
COMMENT=	CUPS driver for Brother laser printers
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c++11

.include "../../print/libcups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
