# $NetBSD: Makefile,v 1.14 2002/11/02 02:42:03 rh Exp $

DISTNAME=		gnome-chess-0.3.3
PKGREVISION=		3
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-chess/0.3/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://arcavia.com/rd/gnome-chess/
COMMENT=		GNOME\'s graphical interface for playing chess

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "SunOS"
LEX= lex
CONFIGURE_ENV+=	LEX=${LEX}
.endif
