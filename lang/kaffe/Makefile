# $NetBSD: Makefile,v 1.36 2002/02/27 03:02:35 tv Exp $
#

DISTNAME=		kaffe-1.0.6
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.kaffe.org/pub/kaffe/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.kaffe.org/
COMMENT=		Virtual machine capable of running Java(tm) code

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/kaffe
CONFIGURE_ARGS+=	--with-rtlibraries="${LOCALBASE}/lib ${X11BASE}/lib"

CPPFLAGS+=		-Dunix -I${LOCALBASE}/include -I${X11BASE}/include

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms \
		${PREFIX}/kaffe/share

test:
	@cd ${WRKSRC}/test && ${MAKE} check

.include "../../devel/gmp/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
