# $NetBSD: Makefile,v 1.3 2001/02/16 14:17:27 wiz Exp $

DISTNAME=	jdb-1.7
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	Package of commands for manipulating flat-ASCII databases

USE_PERL5=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin  --datadir=${PREFIX}/share/jdb

.include "../../mk/bsd.pkg.mk"
