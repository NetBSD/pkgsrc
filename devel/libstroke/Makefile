# $NetBSD: Makefile,v 1.31 2026/06/25 05:00:41 adam Exp $

DISTNAME=	libstroke-0.5.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=s-kro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://etla.net/libstroke/
HOMEPAGE=	https://github.com/s-kro/libstroke
COMMENT=	Stroke translation library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_GTK_CONFIG=no

BUILDLINK_DEPMETHOD.libX11?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
