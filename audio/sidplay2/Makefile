# $NetBSD: Makefile,v 1.3 2012/10/02 23:48:08 asau Exp $
#

DISTNAME=	sidplay-2.0.9
PKGNAME=	sidplay2-2.0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sidplay2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sidplay2.sourceforge.net/
COMMENT=	Tool for playing sidtunes

NOT_FOR_PLATFORM=	Interix-*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

LDFLAGS+=	${LIBOSSAUDIO}

.include "../../audio/libsidplay2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
