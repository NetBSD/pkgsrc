# $NetBSD: Makefile,v 1.9 2003/12/13 00:45:24 wiz Exp $
#

DISTNAME=		swfdec-0.2.1
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swfdec/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://swfdec.sourceforge.net/
COMMENT=		Library for rendering Flash(R) animations and games

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/swfdec.pc.in

.if !defined(PKG_SYSCONFDIR.gtk2) || empty(PKG_SYSCONFDIR.gtk2)
MESSAGE_SUBST+=		PKG_SYSCONFDIR.gtk2="${PKG_SYSCONFBASE}/gtk-2.0"
.else
MESSAGE_SUBST+=		PKG_SYSCONFDIR.gtk2="${PKG_SYSCONFDIR.gtk2}"
.endif

pre-install:
	echo "install:" >${WRKSRC}/plugin/Makefile

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
