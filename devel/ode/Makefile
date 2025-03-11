# $NetBSD: Makefile,v 1.19 2025/03/11 07:52:38 wiz Exp $

DISTNAME=	ode-0.16.5
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/odedevs/ode/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ode.org/
COMMENT=	Library for the simulation of Rigid Body Dynamics
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE=	ode.pc.in

CONFIGURE_ARGS+=	--enable-shared

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
