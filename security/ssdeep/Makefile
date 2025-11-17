# $NetBSD: Makefile,v 1.9 2025/11/17 11:01:24 wiz Exp $

DISTNAME=	ssdeep-2.14.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ssdeep-project/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://ssdeep.sourceforge.net/
COMMENT=	Program computing context triggered piecewise hashes (CTPH)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	automake autoreconf
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
