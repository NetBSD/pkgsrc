# $NetBSD: Makefile,v 1.1.1.1 2002/02/13 23:57:43 wiz Exp $
#

DISTNAME=	gtkballs-2.0.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.antex.ru/pub/unix/dfo/gtkballs/

MAINTAINER=	svs@ropnet.ru
HOMEPAGE=	http://gtkballs.antex.ru/
COMMENT=	GTK+ clone of "Color Lines"

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext

post-install:
	${MV} ${PREFIX}/man/man6/gtkballs.6x ${PREFIX}/man/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
