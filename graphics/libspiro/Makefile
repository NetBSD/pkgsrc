# $NetBSD: Makefile,v 1.3 2020/09/09 08:44:46 wiz Exp $

DISTNAME=	libspiro-dist-20200505
PKGNAME=	libspiro-1.1.0.20200505
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	libspiro
GITHUB_RELEASE=	20200505

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
