# $NetBSD: Makefile,v 1.17 2003/02/18 14:55:58 jmmv Exp $

DISTNAME=		gnome-chess-0.3.3
PKGREVISION=		5
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
