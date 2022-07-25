# $NetBSD: Makefile,v 1.6 2022/07/25 11:12:19 wiz Exp $

DISTNAME=	fdk-aac-0.1.6
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
