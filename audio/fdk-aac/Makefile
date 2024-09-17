# $NetBSD: Makefile,v 1.8 2024/09/17 07:18:00 adam Exp $

DISTNAME=	fdk-aac-2.0.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencore-amr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/opencore-amr/
COMMENT=	Fraunhofer FDK AAC Codec Library
LICENSE=	fraunhofer-license

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	fdk-aac.pc.in

.include "../../mk/bsd.pkg.mk"
