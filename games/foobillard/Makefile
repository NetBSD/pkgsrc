# $NetBSD: Makefile,v 1.3 2004/02/27 01:25:52 snj Exp $
#

DISTNAME=	foobillard-2.8
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://foobillard.sunsite.dk/
COMMENT=	Free OpenGL-billard game

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-glut
.include "../../graphics/glut/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--enable-nvidia=no
.include "../../devel/SDL/buildlink2.mk"
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
