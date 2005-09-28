# $NetBSD: Makefile,v 1.13 2005/09/28 20:52:18 rillig Exp $

DISTNAME=	jdb-1.13
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/jdb

.include "../../mk/bsd.pkg.mk"
