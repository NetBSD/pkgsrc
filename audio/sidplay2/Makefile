# $NetBSD: Makefile,v 1.2 2008/01/21 20:37:49 heinz Exp $
#

DISTNAME=	sidplay-2.0.9
PKGNAME=	sidplay2-2.0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sidplay2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sidplay2.sourceforge.net/
COMMENT=	Tool for playing sidtunes

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

LDFLAGS+=	${LIBOSSAUDIO}

.include "../../audio/libsidplay2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
