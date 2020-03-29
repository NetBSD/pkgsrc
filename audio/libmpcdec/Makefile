# $NetBSD: Makefile,v 1.8 2020/03/29 18:30:06 gutteridge Exp $

DISTNAME=	libmpcdec-1.2.6
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musepack.net/
COMMENT=	Portable Musepack decoder library (V7)
LICENSE=	modified-bsd

CONFLICTS=	musepack-[0-9]*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/mpcdec

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-D__inline=inline
.endif

.include "../../mk/bsd.pkg.mk"
