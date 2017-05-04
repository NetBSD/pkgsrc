# $NetBSD: Makefile,v 1.1 2017/05/04 19:21:35 adam Exp $

DISTNAME=	libspiro-dist-0.5.20150702
PKGNAME=	${DISTNAME:S/-dist-/-/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fontforge.github.io/
COMMENT=	Simplifies the drawing of beautiful curves
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	libspiro
GITHUB_RELEASE=	${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

#PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE+=		libspiro.pc.in

.include "../../mk/bsd.pkg.mk"
