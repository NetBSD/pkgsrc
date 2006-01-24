# $NetBSD: Makefile,v 1.21 2006/01/24 07:32:09 wiz Exp $

DISTNAME=	gtkballs-3.1.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.antex.ru/pub/unix/dfo/gtkballs/ \
		http://gtkballs.antex.ru/dist/

MAINTAINER=	svs@ropnet.ru
HOMEPAGE=	http://gtkballs.antex.ru/
COMMENT=	GTK+ clone of "Color Lines"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

PLIST_SUBST+=	VARBASE=${VARBASE:Q}

post-install:
	${MV} ${PREFIX}/man/man6/gtkballs.6x ${PREFIX}/man/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
