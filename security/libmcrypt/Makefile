# $NetBSD: Makefile,v 1.25 2025/11/17 11:01:22 wiz Exp $

DISTNAME=	libmcrypt-2.5.8
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcrypt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mcrypt.sourceforge.net/
COMMENT=	Crypto algorithms library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include/mutils

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_COMPILER:Mgcc}
CFLAGS+=	-Wno-error=implicit-int
.endif

TEST_TARGET=	check

post-install:
	rmdir ${DESTDIR}${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
