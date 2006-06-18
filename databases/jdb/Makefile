# $NetBSD: Makefile,v 1.14 2006/06/18 12:02:00 rillig Exp $

DISTNAME=	jdb-1.13
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/jdb

REPLACE_PERL+=		crl_to_db *.pm dblib.pl

.include "../../mk/bsd.pkg.mk"
