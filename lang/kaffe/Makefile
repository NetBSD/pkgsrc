# $NetBSD: Makefile,v 1.27 2000/03/21 22:40:56 tron Exp $
#

DISTNAME=		kaffe-1.0.5
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.kaffe.org/pub/kaffe/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.kaffe.org/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		libungif-*:../../graphics/libungif

USE_X11=		yes

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/kaffe
CONFIGURE_ARGS+=	--with-rtlibraries="${LOCALBASE}/lib ${X11BASE}/lib"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-Dunix -I${LOCALBASE}/include -I${X11BASE}/include

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms \
		${PREFIX}/kaffe/share
	if [ -f ${PREFIX}/kaffe/lib/libkaffevm.so ]; then \
		${MV} ${PREFIX}/kaffe/lib/libkaffevm.so \
			${PREFIX}/kaffe/lib/libkaffevm.so.0.0; \
		${MV} ${PREFIX}/kaffe/lib/kaffe/libio.so \
			${PREFIX}/kaffe/lib/kaffe/libio.so.0.0; \
		${MV} ${PREFIX}/kaffe/lib/kaffe/libmanagement.so \
			${PREFIX}/kaffe/lib/kaffe/libmanagement.so.0.0; \
		${MV} ${PREFIX}/kaffe/lib/kaffe/libmicrosoft.so \
			${PREFIX}/kaffe/lib/kaffe/libmicrosoft.so.0.0; \
		${MV} ${PREFIX}/kaffe/lib/kaffe/libnet.so \
			${PREFIX}/kaffe/lib/kaffe/libnet.so.0.0; \
		${MV} ${PREFIX}/kaffe/lib/kaffe/libsecurity.so \
			${PREFIX}/kaffe/lib/kaffe/libsecurity.so.0.0; \
	fi

.include "../../mk/bsd.pkg.mk"
