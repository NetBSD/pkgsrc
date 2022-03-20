# $NetBSD: Makefile,v 1.4 2022/03/20 01:23:24 schmonz Exp $

DISTNAME=	brlaser-6.1
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
