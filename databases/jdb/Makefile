# $NetBSD: Makefile,v 1.2 2000/04/27 14:44:27 bad Exp $

DISTNAME=	jdb-1.7
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html

USE_PERL5=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin  --datadir=${PREFIX}/share/jdb

.include "../../mk/bsd.pkg.mk"
