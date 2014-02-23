# $NetBSD: Makefile,v 1.29 2014/02/23 00:35:32 schmonz Exp $

DISTNAME=	libcaca-0.99.beta18
PKGNAME=	${DISTNAME:S/beta//}
CATEGORIES=	graphics
MASTER_SITES=	http://caca.zoy.org/files/libcaca/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://caca.zoy.org/
COMMENT=	Graphics library that outputs text instead of pixels, in colour
# LICENSE=	wtfpl

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-Q]-*
PKGCONFIG_OVERRIDE+=	caca/caca.pc.in

CHECK_FILES_SKIP+=	${PREFIX}/lib/libcucul.*

.include "options.mk"

CONFIGURE_ARGS+=	--disable-doc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
LDFLAGS+=	-ldl
.endif

.include "../../mk/bsd.pkg.mk"
