# $NetBSD: Makefile,v 1.12 2004/01/24 13:30:56 grant Exp $
#

DISTNAME=	gtkballs-3.0.1
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.antex.ru/pub/unix/dfo/gtkballs/ \
		http://gtkballs.antex.ru/dist/

MAINTAINER=	svs@ropnet.ru
HOMEPAGE=	http://gtkballs.antex.ru/
COMMENT=	GTK+ clone of "Color Lines"

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--without-included-gettext

post-install:
	${MV} ${PREFIX}/man/man6/gtkballs.6x ${PREFIX}/man/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
