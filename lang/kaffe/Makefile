# $NetBSD: Makefile,v 1.33 2001/05/22 09:32:24 wiz Exp $
#

DISTNAME=		kaffe-1.0.6
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.kaffe.org/pub/kaffe/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.kaffe.org/
COMMENT=		Virtual machine capable of running Java(tm) code

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.11:../../graphics/png
DEPENDS+=		libungif-*:../../graphics/libungif
DEPENDS+=		gmp>=3.0.0:../../devel/gmp

USE_X11=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/kaffe
CONFIGURE_ARGS+=	--with-rtlibraries="${LOCALBASE}/lib ${X11BASE}/lib"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-Dunix -I${LOCALBASE}/include -I${X11BASE}/include

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms \
		${PREFIX}/kaffe/share

test:
	@cd ${WRKSRC}/test && ${MAKE} check

.include "../../mk/bsd.pkg.mk"
