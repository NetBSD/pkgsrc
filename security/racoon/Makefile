# $NetBSD: Makefile,v 1.50 2002/06/17 10:06:50 drochner Exp $
#

DISTNAME=	racoon-20020507a
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.kame.net/
COMMENT=	KAME racoon IKE daemon

CRYPTO=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

USE_BUILDLINK_ONLY=	yes

CONFLICTS+=	racoon-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/racoon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-debug
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif
CONFIGURE_ARGS+=--sysconfdir=/etc/racoon
.if defined(PKGREVISION)
CONFIGURE_ARGS+=--with-pkgversion=netbsd-pkgsrc-20020507anb${PKGREVISION}
.else
CONFIGURE_ARGS+=--with-pkgversion=netbsd-pkgsrc-20020507a
.endif

pre-configure:
	(cd ${WRKSRC}/../libipsec; ${MAKE})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/racoon
	for i in FAQ README.certificate README.gssapi; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/racoon; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/racoon
	${INSTALL_DATA} ${WRKSRC}/samples/racoon.conf.sample \
		${PREFIX}/share/examples/racoon

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
