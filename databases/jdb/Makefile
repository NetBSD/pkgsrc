# $NetBSD: Makefile,v 1.5 2002/11/15 00:35:20 jlam Exp $

DISTNAME=	jdb-1.7
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	commands for manipulating flat-ASCII databases

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/jdb

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
