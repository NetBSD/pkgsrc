# $NetBSD: Makefile,v 1.19 2007/04/30 19:26:23 adam Exp $

DISTNAME=	libmcrypt-2.5.8
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcrypt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcrypt.sourceforge.net/
COMMENT=	Crypto algorithms library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

pre-install:
	mkdir ${PREFIX}/include/mutils

post-install:
	rmdir ${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
