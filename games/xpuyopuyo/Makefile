# $NetBSD: Makefile,v 1.3 2000/05/29 16:40:55 jlam Exp $

DISTNAME=		xpuyopuyo-0.3.8
CATEGORIES=		games x11
MASTER_SITES=		http://chaos2.org/xpuyopuyo/ \
			http://lenin.dabney.caltech.edu./~justins/xpuyopuyo/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://chaos2.org/xpuyopuyo/

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		xpm-*:../../graphics/xpm

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gnome

.include "../../mk/bsd.pkg.mk"
