# $NetBSD: Makefile,v 1.7 2025/04/21 16:21:40 wiz Exp $

DISTNAME=	sidplay-2.0.9
PKGNAME=	sidplay2-2.0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sidplay2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sidplay2.sourceforge.net/
COMMENT=	Tool for playing sidtunes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

LDFLAGS+=	${LIBOSSAUDIO}

.include "../../audio/libsidplay2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
