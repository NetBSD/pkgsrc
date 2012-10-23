# $NetBSD: Makefile,v 1.6 2012/10/23 17:19:11 asau Exp $
#

DISTNAME=		synergy-1.2.7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synergy2/}

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://synergy2.sourceforge.net/
COMMENT=		Let an user share a mouse and keyboard among computers

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
