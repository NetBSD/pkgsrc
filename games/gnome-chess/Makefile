# $NetBSD: Makefile,v 1.18 2003/05/02 11:54:56 wiz Exp $

DISTNAME=		gnome-chess-0.3.3
PKGREVISION=	6
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-chess/0.3/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://arcavia.com/rd/gnome-chess/
COMMENT=		GNOME\'s graphical interface for playing chess

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "SunOS"
LEX= lex
CONFIGURE_ENV+=	LEX=${LEX}
.endif
