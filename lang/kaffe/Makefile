# $NetBSD: Makefile,v 1.23 1999/10/09 20:15:48 jlam Exp $
#

DISTNAME=		kaffe-1.0.b4
WRKSRC=			${WRKDIR}/kaffe-1.0b4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.transvirtual.com/pub/kaffe/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.transvirtual.com/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.3:../../graphics/png
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
		mv ${PREFIX}/kaffe/lib/libkaffevm.so \
			${PREFIX}/kaffe/lib/libkaffevm.so.0.0; \
		mv ${PREFIX}/kaffe/lib/kaffe/libio.so \
			${PREFIX}/kaffe/lib/kaffe/libio.so.0.0; \
		mv ${PREFIX}/kaffe/lib/kaffe/libmanagement.so \
			${PREFIX}/kaffe/lib/kaffe/libmanagement.so.0.0; \
		mv ${PREFIX}/kaffe/lib/kaffe/libnet.so \
			${PREFIX}/kaffe/lib/kaffe/libnet.so.0.0; \
	fi

.include "../../mk/bsd.pkg.mk"
