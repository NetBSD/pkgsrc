# $NetBSD: Makefile,v 1.4 2004/03/07 04:57:32 snj Exp $
#

DISTNAME=	foobillard-2.9
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://foobillard.sunsite.dk/
COMMENT=	Free OpenGL-billard game

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-glut
.include "../../graphics/glut/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-nvidia=no
.include "../../devel/SDL/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
