# $NetBSD: Makefile,v 1.2 2002/04/06 18:58:32 wiz Exp $
#

DISTNAME=	gtkballs-3.0.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.antex.ru/pub/unix/dfo/gtkballs/ \
		http://gtkballs.antex.ru/dist/

MAINTAINER=	svs@ropnet.ru
HOMEPAGE=	http://gtkballs.antex.ru/
COMMENT=	GTK+ clone of "Color Lines"

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext

post-install:
	${MV} ${PREFIX}/man/man6/gtkballs.6x ${PREFIX}/man/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
