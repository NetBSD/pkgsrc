# $NetBSD: Makefile,v 1.3 2009/01/20 20:29:18 sketch Exp $
#

DISTNAME=	libmpcdec-1.2.6
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musepack.net/
COMMENT=	Portable Musepack decoder library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/mpcdec

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-D__inline=inline
.endif

.include "../../mk/bsd.pkg.mk"
