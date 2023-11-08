# $NetBSD: Makefile,v 1.11 2023/11/08 13:20:40 wiz Exp $

DISTNAME=	brlaser-6.2
PKGREVISION=	5
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
