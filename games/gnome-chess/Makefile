# $NetBSD: Makefile,v 1.13 2002/10/26 20:04:31 bouyer Exp $

DISTNAME=	gnome-chess-0.3.3
PKGREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-chess/0.3/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://arcavia.com/rd/gnome-chess/
COMMENT=	GNOME's graphical interface for playing chess

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${X11PREFIX}/var/lib

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "SunOS"
LEX= lex
CONFIGURE_ENV+=	LEX=${LEX}
.endif
