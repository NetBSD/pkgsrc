# $NetBSD: Makefile,v 1.20 2009/02/10 00:08:35 joerg Exp $

DISTNAME=	libmcrypt-2.5.8
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcrypt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcrypt.sourceforge.net/
COMMENT=	Crypto algorithms library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include/mutils

post-install:
	rmdir ${DESTDIR}${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
