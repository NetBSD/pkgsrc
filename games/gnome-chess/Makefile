# $NetBSD: Makefile,v 1.33 2005/04/11 21:45:50 tv Exp $

DISTNAME=		gnome-chess-0.3.3
PKGREVISION=		15
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-chess/0.3/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/softwaremap/projects/gnome-chess/
COMMENT=		GNOME\'s graphical interface for playing chess

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "SunOS"
LEX= lex
CONFIGURE_ENV+=	LEX=${LEX}
.endif
