# $NetBSD: Makefile,v 1.24 2000/10/10 09:47:50 itojun Exp $
#

DISTNAME=	racoon-20001010a
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http:/www.kame.net/

CRYPTO=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

# we rely upon 1.5-based /usr/lib/libcrypto, or pkgsrc/security/openssl.
# between 1.4 and 1.5, there were period where we had RSA-less
# /usr/lib/libcrypto.  we do not support that configuration in the pkgsrc.
USE_SSL=	yes
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include CFLAGS=-I${LOCALBASE}/include \
		LIBS="-L${LOCALBASE}/lib -L${WRKSRC}/../libipsec"

CONFLICTS+=	racoon-*

WRKSRC=		${WRKDIR}/${DISTNAME}/racoon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-debug
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif
CONFIGURE_ARGS+=--sysconfdir=/etc/racoon

pre-configure:
	(cd ${WRKSRC}/../libipsec; ${MAKE})

post-install:
	${MKDIR} ${PREFIX}/share/doc/racoon
	for i in FAQ README.certificate; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/racoon; \
	done
	${MKDIR} ${PREFIX}/share/examples/racoon
	${INSTALL_DATA} ${WRKSRC}/samples/racoon.conf.sample \
		${PREFIX}/share/examples/racoon

.include "../../mk/bsd.pkg.mk"
