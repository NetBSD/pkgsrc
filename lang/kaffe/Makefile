# $NetBSD: Makefile,v 1.20 1999/08/07 10:23:52 drochner Exp $
#

DISTNAME=		kaffe-1.0.b4
WRKSRC=			${WRKDIR}/kaffe-1.0b4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.transvirtual.com/pub/kaffe/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.transvirtual.com/

DEPENDS=		jpeg-6b:../../graphics/jpeg \
			png-1.0.3:../../graphics/png \
			giflib-3.0:../../graphics/giflib

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/kaffe
CONFIGURE_ARGS+=	--with-rtlibraries="${LOCALBASE}/lib ${X11BASE}/lib"
CONFIGURE_ENV=		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
			CPPFLAGS="-Dunix -I${LOCALBASE}/include -I${X11BASE}/include"

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms \
		${PREFIX}/kaffe/share

.include "../../mk/bsd.pkg.mk"
