# $NetBSD: Makefile,v 1.7 2020/01/26 17:30:43 rillig Exp $

DISTNAME=	libmpcdec-1.2.6
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musepack.net/
COMMENT=	Portable Musepack decoder library (V7)
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/mpcdec

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-D__inline=inline
.endif

.include "../../mk/bsd.pkg.mk"
