# $NetBSD: Makefile,v 1.24 2003/11/12 01:31:49 salo Exp $

DISTNAME=		gnome-chess-0.3.3
PKGREVISION=		9
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-chess/0.3/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/softwaremap/projects/gnome-chess/
COMMENT=		GNOME\'s graphical interface for playing chess

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs

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
