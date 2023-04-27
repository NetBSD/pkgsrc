# $NetBSD: Makefile,v 1.4 2023/04/27 12:29:50 wiz Exp $

DISTNAME=	libspiro-dist-20221101
PKGNAME=	libspiro-1.3.0.20221101
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	libspiro
GITHUB_RELEASE=	20221101

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fontforge.github.io/
COMMENT=	Simplifies the drawing of beautiful curves
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME:S/-dist//}

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

#PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE+=		libspiro.pc.in

.include "../../mk/bsd.pkg.mk"
