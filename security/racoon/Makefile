# $NetBSD: Makefile,v 1.22 2000/09/23 21:25:06 itojun Exp $
#

DISTNAME=	racoon-20000923a
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

# openssl is necessary for RSA libraries
# if PATENTEDOPENSSLSRC is defined, then we assume that
# RSA already exists in the OpenSSL built as part of the
# base distribution.
# XXX the check chokes with cross build
.if !defined(PATENTEDOPENSSLSRC) && !exists(/usr/include/openssl/rsa.h)
DEPENDS+=	openssl-0.9.*:../../security/openssl
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include CFLAGS=-I${LOCALBASE}/include \
		LIBS="-L${LOCALBASE}/lib -L${WRKSRC}/../libipsec"
.else
CONFIGURE_ENV+=	LIBS="-L${WRKSRC}/../libipsec"
.endif

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
