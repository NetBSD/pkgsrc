# $NetBSD: Makefile,v 1.9 2004/04/25 17:45:31 snj Exp $

DISTNAME=	jdb-1.12
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/jdb

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
