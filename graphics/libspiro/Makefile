# $NetBSD: Makefile,v 1.5 2024/09/13 08:15:40 wiz Exp $

DISTNAME=	libspiro-dist-20240903
PKGNAME=	libspiro-1.5.0.20240903
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	libspiro
GITHUB_RELEASE=	20240903

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fontforge.github.io/
COMMENT=	Simplifies the drawing of beautiful curves
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME:S/-dist//}

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=		libspiro.pc.in

.include "../../mk/bsd.pkg.mk"
