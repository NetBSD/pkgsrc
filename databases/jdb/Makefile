# $NetBSD: Makefile,v 1.1.1.1 1999/05/17 16:58:30 bad Exp $

DISTNAME=	jdb-1.5
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html

USE_PERL5=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin

.include "../../mk/bsd.pkg.mk"
