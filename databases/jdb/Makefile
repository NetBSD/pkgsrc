# $NetBSD: Makefile,v 1.8 2003/12/15 20:18:33 bad Exp $

DISTNAME=	jdb-1.12
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/jdb

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
